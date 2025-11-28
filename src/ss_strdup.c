/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_strdup.c                                                  */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 20:53 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

char *ss_strdup(const char *s1)
{
	if (!s1)
		return NULL;

	size_t len = ss_strlen(s1) + 1;
	char *p = malloc(len);
	if (!p)
		return NULL;

	return ss_memcpy(p, s1, len);
}
