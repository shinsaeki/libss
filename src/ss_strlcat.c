/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_strlcat.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 13:13 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

size_t ss_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t len_dst = ss_strlen(dst);
	size_t len_src = ss_strlen(src);

	if (dstsize <= len_dst)
		return dstsize + len_src;

	size_t len_cpy = dstsize - len_dst - 1;

	dst += len_dst;

	while (*src && len_cpy--)
		*dst++ = *src++;
	*dst = '\0';
	return len_dst + len_src;
}
