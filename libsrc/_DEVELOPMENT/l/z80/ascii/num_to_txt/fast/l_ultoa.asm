
XLIB l_ultoa
LIB l_utoa, l0_utoa, l_setmem_de

l_ultoa:

   ; write unsigned long decimal to ascii buffer
   ;
   ; enter : dehl = unsigned integer
   ;           bc = char *buffer
   ;         carry set to write leading zeroes
   ;
   ; exit  :   de = char *buffer (one byte past last char written)
   ;         carry reset
   ;
   ; uses  : af, bc, de, hl, bc', hl'

   inc e
   inc d

   dec e
   jr nz, bit_24_32

   dec d
   jr nz, bit_32

   ; sixteen bits
   
   ld e,c
   ld d,b
   
   jp nc, l_utoa
   
   ld a,'0'
   call l_setmem_de - 10       ; write five leading zeroes

   jp l_utoa

bit_24_32:
   
   dec d
   jr nz, bit_32
   
   ; twenty four bits

   jr nc, bit_32

   ld a,'0'
   ld (bc),a
   inc bc
   ld (bc),a
   inc bc


bit_32:

   ; z flag set if 24 bits
   ; c flag set if leading zeroes

   push de
   exx
   pop hl
   
   ld bc,$0100                 ; end of constants
   push bc
   push bc
   
   ld bc,$ffff                 ; -10,000 (LSW + 256)
   push bc
   ld bc,$d9f0
   push bc
   
   ld bc,$fffe                 ; -100,000 (LSW + 256)
   push bc
   ld bc,$7a60
   push bc
   
   ld bc,$fff0                 ; -1,000,000 (LSW + 256)
   push bc
   ld bc,$bec0
   push bc
   
   ld bc,$ff67                 ; -10,000,000 (LSW + 256)
   push bc
   ld bc,$6980
   
   jr z, bit_24
   inc b
   push bc
   
   ld bc,$fa0a                 ; -100,000,000 (LSW + 256)
   push bc
   ld bc,$2000
   push bc
   
   ld bc,$3600                 ; -1,000,000,000
   push bc
   ld bc,$c465

bit_24:

   exx
   ld e,c
   ld d,b
   pop bc
   
   ; hl'hl = long
   ; bc'bc = first divisor
   ;    de = char *
   ; carry set to write leading zeroes
   
   jr c, leading_zeroes
   
no_leading_zeroes:

   call divide
   cp '0'
   jr nz, write
   
   exx
   pop bc                      ; next constant from stack
   exx
   pop bc
   
   djnz no_leading_zeroes
   
   or a
   jr do_16                    ; complete job in 16 bits

leading_zeroes:

   call divide

write:

   ld (de),a
   inc de
   
   exx
   pop bc                      ; next constant from stack
   exx
   pop bc
   
   djnz leading_zeroes
   
   scf

do_16:

   ld bc,0+256
   push bc
   
   ld bc,-10+256
   push bc
      
   ld bc,-100+256
   push bc
   
   ld bc,-1000
   jp l0_utoa                   ; complete job in 16 bits


divide:

   ; hl'hl = dividend
   ; bc'bc = divisor
   
   ld a,'0'-1

divloop:

   inc a
   
   add hl,bc
   exx
   adc hl,bc
   exx
   
   jp c, divloop
   
   sbc hl,bc
   exx
   sbc hl,bc
   exx
   
   ret
