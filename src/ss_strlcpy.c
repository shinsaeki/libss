/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_strlcpy.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 12:22 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

size_t ss_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t len_src = ss_strlen(src);

	if (dstsize == 0)
		return len_src;
	if (0 < dstsize)
	{
		while (--dstsize && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return len_src;
}
