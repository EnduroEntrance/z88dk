; void sp1_IterateSprChar(struct sp1_ss *s, void *hook1)

XDEF _sp1_IterateSprChar

_sp1_IterateSprChar:

   pop af
   pop hl
   pop bc
   
   push bc
   push hl
   push af
   
   push ix
   
   ld ixl,c
   ld ixh,b
   
   call asm_sp1_IterateSprChar
   
   pop ix
   ret

   INCLUDE "temp/sp1/spectrum/sprites/asm_sp1_IterateSprChar.asm"
