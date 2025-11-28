/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_memset.c                                                  */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 21:55 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

void *ss_memset(void *b, int c, size_t len)
{
	unsigned char *p = b;
	unsigned char uc = c;

	while (len--) 
	{
		*p = uc;
		p++;
	}

	return b;
}
