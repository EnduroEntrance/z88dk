; unsigned char esx_f_rename(unsigned char *old, unsigned char *new)

SECTION code_esxdos

PUBLIC _esx_f_rename_callee

EXTERN asm_esx_f_rename

_esx_f_rename_callee:

   pop af
   pop hl
   pop de
   push af
   
   jp asm_esx_f_rename
