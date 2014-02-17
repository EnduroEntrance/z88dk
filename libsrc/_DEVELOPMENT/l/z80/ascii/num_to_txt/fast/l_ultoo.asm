
XLIB l_ultoo

LIB l_utoo, l_setmem_de
LIB l1_utoo_lz, l1_utoo_nlz
LIB l2_utoo_lz, l2_utoo_nlz
LIB l3_utoo_lz, l3_utoo_nlz

l_ultoo:

   ; write unsigned octal long to ascii buffer
   ;
   ; enter : dehl = unsigned long
   ;           bc = char *buffer
   ;         carry set to write leading zeroes
   ;
   ; exit  : de   = char *buffer (one byte past last char written)
   ;         carry set if in write loop
   ;
   ; uses  : af, bc, de, hl

   inc d
   dec d
   jr nz, _32_bit
   
   inc e
   dec e
   jr nz, _24_bit
   
_16_bit:
   
   ld e,c
   ld d,b                      ; de = char *buffer
   
   jp nc, l_utoo

   ld a,'0'
   call l_setmem_de - 10       ; write five leading zeroes
   
   jp l_utoo

_24_bit:

   push hl                     ; save LSW
   ld h,e
   
   ld e,c
   ld d,b                      ; de = char *buffer

   ld c,h
   ld b,2
   
   jr c, leading_zeroes_24
   
   xor a
   call l1_utoo_nlz

rejoin_24:

   ld a,c
   and $03
   
   pop hl
   
   ld b,6
   jp l3_utoo_lz

leading_zeroes_24:

   ld a,'0'
   call l_setmem_de - 6

   xor a
   call l1_utoo_lz
   
   jp rejoin_24

_32_bit:

   push hl                     ; save LSW
   ex de,hl
   
   ld e,c
   ld d,b                      ; de = char *buffer
   
   ld c,l
   ld b,5

   ld a,0
   call c, l2_utoo_lz
   call nc, l2_utoo_nlz

   jp rejoin_24
