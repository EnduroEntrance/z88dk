/*
 *      Small C+ Library
 *
 *      conio.h - old apps compatibility
 *	this helps expecially with the kbhit() instruction
 *	it exists on many old compilers; the mingw port has it
 *	on "conio.h", so here it is !
 *
 *      stefano - 18/3/2004
 *
 *	$Id: conio.h,v 1.2 2010-09-19 00:24:08 dom Exp $
 */

#ifndef __CONIO_H__
#define __CONIO_H__

// this is used by getch, putch and ungetch.
#include <sys/compiler.h>
#include <stdio.h>

#define getch()  fgetc(stdin)
#define getche() getch()                // not sure about this one...
#define putch(bp,fp) fputc(bp,fp)
// #define ungetch(bp)  ungetc(bp,stdout)  // this one doesn't work

#define kbhit() (getk() ? 1 : 0)


#endif /* _CONIO_H */
