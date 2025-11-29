/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_substr.c                                                  */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 21:29 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

char *ss_substr(const char *s, unsigned int start, size_t len)
{
	if (!s)
		return NULL;

	size_t len_s = ss_strlen(s);
	size_t len_sub = len;

	if (len_s <= start)
		return ss_strdup("");
	if (len_s < start + len)
		len_sub = len_s - start;
	
	char *p = malloc(len_sub + 1);
	if (!p)
		return NULL;

	ss_memcpy(p, s + start, len_sub);
	p[len_sub] = '\0';

	return p;
}
