/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_strlen.c                                                  */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 17:30 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

size_t ss_strlen(const char *s)
{
	size_t len = 0;
	while(s[len]) len++;

	return len;
}
