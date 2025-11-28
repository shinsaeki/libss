/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_strrchr.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 21:36 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

char *ss_strrchr(const char *s, int c)
{
	const char *p = NULL;

	for (;;)
	{
		if (*s == c) p = s;
		if (!*s) return (char *)p;
		s++;
	}
}
