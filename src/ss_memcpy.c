/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_memcpy.c                                                  */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 10:02 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

void *ss_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *uc_dst = dst;
	const unsigned char *uc_src = src;

	while (n--)
	{
		*uc_dst = *uc_src;
		uc_dst++;
		uc_src++;
	}
	return dst;
}
