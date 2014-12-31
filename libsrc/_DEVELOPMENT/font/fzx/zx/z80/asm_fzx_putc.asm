
; ===============================================================
; FZX driver - Copyright (c) 2013 Einar Saukas
; FZX format - Copyright (c) 2013 Andrew Owen
; ===============================================================
; Modified for z88dk - aralbrec
; * removed self-modifying code
; * removed control code sequences
; * added colour and rop modes
; * added window
; * made fields 16-bit for hi-res
; ===============================================================

SECTION code_font_fzx

PUBLIC asm_fzx_putc

EXTERN l_jpix, error_zc
EXTERN asm_zx_pxy2saddr, asm_zx_saddr2aaddr, asm_zx_saddrpdown

asm_fzx_putc:

   ; print fzx glyph to window on screen
   ;
   ; enter :  c = ascii code
   ;         ix = struct fzx_state *
   ;
   ; exit  : ix = struct fzx_state *
   ;
   ;         success
   ;
   ;            hl = screen address below glyph (may be off window)
   ;            fzx_state.x += glyph width
   ;            carry reset
   ;
   ;         fail if glyph does not fit horizontally
   ;
   ;            a = 0
   ;            carry set
   ;
   ;         fail if glyph does not fit vertically
   ;
   ;            a = 1
   ;            carry set
   ;
   ; uses  : af, bc, de, hl, af'

   ld l,(ix+3)
   ld h,(ix+4)                 ; hl = struct fzx_font *
   
   ld a,(hl)
   ex af,af'                   ; a' = font height
   
   inc hl
   ld a,(hl)
   push af                     ; save tracking
   
   inc hl                      ; hl = & fzx_font.last_char

   ld a,c                      ; a = char
   dec a
   
   cp (hl)
   jr nc, char_undefined       ; if char > fzx_font.last_char
   
   sub 31                      ; a = char - 32
   jr nc, char_defined

char_undefined:

   ld a,'?'-32                 ; print '?' for undefined chars

char_defined:

   inc hl

   ; hl = & first fzx_char (code 32)
   ; ix = struct fzx_state *
   ;  a = char-32
   ;  a'= font height
   ; stack = tracking
   
   ld c,l
   ld b,h
   
   ld l,a
   ld h,0
   
   ld e,l
   ld d,h
   
   add hl,hl
   add hl,de
   add hl,bc                   ; hl = struct fzx_char *
   
   ; hl = struct fzx_char *
   ; ix = struct fzx_state *
   ;  a'= font height
   ; stack = tracking
   
   ld c,(hl)
   inc hl
   ld a,(hl)
   and $3f
   ld b,a                      ; bc = bitmap offset
   
   xor (hl)
   rlca
   rlca
   ld e,a                      ; e = kern
   
   push hl                     ; save & fzx_char + 1b
   
   add hl,bc
   dec hl                      ; hl = bitmap address
   
   ex (sp),hl
   inc hl                      ; hl = & fzx_char.shift_width_1
   
   ; ix = struct fzx_state *
   ; hl = & fzx_char.shift_width_1
   ;  e = kern
   ;  a'= font height
   ; stack = tracking, & bitmap
   
   xor a
   
   rld
   push af                     ; save shift

   rld
   ld c,a                      ; c = a = width - 1

   rld                         ; restore shift_width_1

   ; ix = struct fzx_state *
   ; hl = & fzx_char.shift_width_1
   ;  c = width - 1
   ;  e = kern
   ;  a'= font height
   ; stack = tracking, & bitmap, shift
   
   inc hl                      ; hl = & fzx_char.next
   
   ld a,(hl)
   add a,l
   ld b,a                      ; b = LSB of next char bitmap address
   
   ; ix = struct fzx_state *
   ;  b = LSB of end of bitmap
   ;  c = width - 1
   ;  e = kern
   ;  a'= font height
   ; stack = tracking, & bitmap, shift

   ; check if glyph fits window horizontally
   ; spectrum resolution 8-bits so ignore MSB in coordinates
   
   ld a,(ix+6)
   or a
   jr nz, x_too_large          ; if x > 255
   
   ld a,(ix+5)                 ; a = x coord
   ld d,(ix+17)                ; d = left_margin
   
   cp d
   jr nc, exceeds_margin

   ld a,d

exceeds_margin:

   sub e                       ; a = x - kern
   jr nc, x_ok
   
   xor a

x_ok:

   ld e,a                      ; e = x coord

   add a,c                     ; a = x + width - 1
   jr c, x_too_large           ; if glyph exceeds right edge of window
   
   cp (ix+11)
   jr c, width_adequate
   
   ld a,(ix+12)
   or a
   jr z, x_too_large           ; if glyph exceeds right edge of window

width_adequate:

   ld a,(ix+9)                 ; a = window.x
   add a,e
   ld l,e                      ; l = absolute x coord

   ; ix = struct fzx_state *
   ;  b = LSB of end of bitmap
   ;  c = width - 1
   ;  l = absolute x coord
   ;  a'= font height
   ; stack = tracking, & bitmap, shift
   
   ; check if glyph fits window vertically
   
   ld a,(ix+8)
   or a
   jr nz, y_too_large          ; if y > 255
   
   ld h,(ix+7)                 ; h = y coord
   ex af,af'                   ; a = font height
   
   add a,h
   jr c, y_too_large           ; if glyph exceeds bottom edge of window
   
   cp (ix+15)
   jr nc, y_too_large          ; if glyph exceeds bottom edge of window
   
   pop af                      ; a = vertical shift
   
   add a,h                     ; + y coord
   add a,(ix+13)               ; + window.y
   
   ld h,a                      ; h = absolute y coord
   
   ; ix = struct fzx_state *
   ;  b = LSB of end of bitmap
   ;  c = width - 1
   ;  l = absolute x coord
   ;  h = absolute y coord
   ; stack = tracking, & bitmap

   pop af
   push bc
   push af

   call asm_zx_pxy2saddr       ; hl = screen address, de = coords

   ld a,e
   and $07                     ; a = rotate amount, z = zero rotate

   ex (sp),hl                  ; hl = & bitmap
   ld e,b                      ; e = LSB of end of bitmap
   
   ex af,af'
   
   ld a,c                      ; a = width - 1
   cp 8
   jr nc, wide_char

narrow_char:

   ex af,af'
   scf
   ex af,af'

wide_char:
   
   ; ix = struct fzx_state *
   ; hl = & bitmap
   ;  e = LSB of end of bitmap
   ; af'= rotate 0-7, carry = narrow char, z = zero rotate
   ; stack = tracking, width - 1, screen address

   ld a,l
   cp e
   jr nz, draw_attr          ; if bitmap is not zero length

   ; glyph drawn, update x coordinate

   ; ix = struct fzx_state *
   ; stack = tracking, width - 1, screen address

draw_attr_ret:

   pop hl                      ; hl = screen address
   pop bc                      ; c = width - 1
   pop af                      ; a = tracking

   inc a
   add a,c
   add a,(ix+5)                ; a = new x coordinate
   
   ld (ix+5),a                 ; store new x coordinate
   ret nc
   ld (ix+6),1
   
   or a
   ret

x_too_large:

   ; ix = struct fzx_state *
   ; stack = tracking, & bitmap, shift

   xor a
   jp error_zc - 3

y_too_large:

   ; ix = struct fzx_state *
   ; stack = tracking, & bitmap, shift

   ld a,1
   jp error_zc - 3

draw_attr:

   ; ix = struct fzx_state *
   ; hl = & bitmap
   ;  e = LSB of end of bitmap
   ; af'= rotate 0-7, carry = narrow char, z = zero rotate
   ; stack = screen address

   ex (sp),hl
   push hl                     ; save screen address
   
   call asm_zx_saddr2aaddr     ; hl = attribute address
   
   ld a,(ix+20)                ; a = foregound mask
   and (hl)                    ; keep screen attribute bits
   or (ix+19)                  ; mix foregound colour
   
   ld (hl),a                   ; new colour to screen
   
   pop hl                      ; hl = screen address
   ex (sp),hl

   ld b,8                      ; row count until next attr

draw_row:

   ; ix = struct fzx_state *
   ; hl = & bitmap
   ;  b = row count until next attr
   ;  e = LSB of end of bitmap
   ; af'= rotate 0-7, carry = narrow char, z = zero rotate
   ; stack = screen address
   
   ; bitmap bytes
   
   ld d,(hl)                   ; first bitmap byte
   inc hl
   
   ld c,(hl)                   ; second bitmap byte
   inc hl

   xor a                       ; third bitmap byte
   
   ; narrow char test
   
   ex af,af'
   jr nc, rotate_bitmap        ; if wide char
   
   dec hl                      ; no second bitmap byte
   ld c,0                      ; second byte = 0

rotate_bitmap:

   jr z, no_rotate

   push bc                     ; save row count until next attr
   ld b,a                      ; b = shift amount
   
   ex af,af'

rotate_loop:

   srl d                       ; rotate bitmap DCA right one pixel
   rr c
   rra
   
   djnz rotate_loop
   
   ex af,af'
   pop bc                      ; b = row count until next attr

no_rotate:

   ex af,af'
   ex (sp),hl
   
   ; ix = struct fzx_state *
   ; hl = screen address
   ;  b = row count until next attr
   ;  e = LSB of end of bitmap
   ; dca= bitmap bytes
   ; af'= rotate 0-7, carry = narrow char, z = zero rotate
   ; stack = & bitmap

   call l_jpix                 ; call fzx_draw
   call asm_zx_saddrpdown      ; move screen address down one pixel
   
   ex (sp),hl                  ; hl = & bitmap
   
   ld a,l
   cp e
   jr z, draw_attr_ret         ; if bitmap finished
   
   djnz draw_row               ; if not time for new attr
   jr draw_attr
