/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_calloc.c                                                  */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 14:06 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

void *ss_calloc(size_t count, size_t size)
{
	if (size != 0 && count > SIZE_MAX / size)
		return NULL;

	size_t total = count * size;
	char *p = malloc(total);
	if (!p)
		return NULL;

	ss_bzero(p, total);

	return (void *)p;
}
