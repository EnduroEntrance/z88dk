; void sp1_IterateUpdateSpr(struct sp1_ss *s, void *hook2)

XDEF _sp1_IterateUpdateSpr

_sp1_IterateUpdateSpr:

   pop af
   pop hl
   pop bc
   
   push bc
   push hl
   push af
   
   push ix
   
   ld ixl,c
   ld ixh,b
   
   call asm_sp1_IterateUpdateSpr
   
   pop ix
   ret

   INCLUDE "temp/sp1/spectrum/sprites/asm_sp1_IterateUpdateSpr.asm"
