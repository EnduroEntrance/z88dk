; unsigned char esx_f_opendir_ex(unsigned char *dirname,uint8_t mode)

SECTION code_esxdos

PUBLIC _esx_f_opendir_ex_callee

EXTERN asm_esx_f_opendir_ex

_esx_f_opendir_ex_callee:

   pop af
   pop hl
   dec sp
   pop bc
   push af
   
   jp asm_esx_f_opendir_ex
