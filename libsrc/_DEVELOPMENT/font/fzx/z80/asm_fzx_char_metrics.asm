
SECTION code_font_fzx

PUBLIC asm_fzx_char_metrics

EXTERN __fzx_char_struct

asm_fzx_char_metrics:

   ; enter :  a = char
   ;         hl = struct fzx_font *
   ;
   ; exit  : hl = bitmap address
   ;          a = kern
   ;          c = vertical shift
   ;          b = width - 1
   ;
   ; uses  : af, bc, hl
   
   call __fzx_char_struct
   
   ld c,(hl)
   inc hl
   ld a,(hl)
   and $3f
   ld b,a                      ; bc = bitmap offset
   
   xor (hl)
   rlca
   rlca

   push af                     ; save kern
   push hl                     ; save & fzx_char + 1b
   
   add hl,bc
   dec hl
   
   ex (sp),hl
   inc hl                      ; hl = & fzx_char.shift_width_1
   
   xor a
   
   rld
   ld c,a                      ; c = shift
   
   rld
   ld b,a                      ; b = width - 1
   
   rld
   
   pop af
   pop hl
   
   ret
