/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_memmove.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 10:19 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

void *ss_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *uc_dst = dst;
	const unsigned char *uc_src = src;

	if (uc_src < uc_dst && uc_dst < uc_src + n)
	{
		while (n--)
			uc_dst[n] = uc_src[n];
	}
	else
		return ss_memcpy(dst, src, n);
	return dst;
}

