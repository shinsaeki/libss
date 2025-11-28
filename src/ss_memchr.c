/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_memchr.c                                                  */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 23:58 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

void *ss_memchr(const void *s, int c, size_t n)
{
	const unsigned char *p = s;
	unsigned char uc = c;

	while (n--)
	{
		if (*p == uc)
			return (void *)p;
		p++;
	}
	return NULL;
}
