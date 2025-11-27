/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_tolower.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 19:36 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

int ss_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return c + ('a' - 'A');
	return c;
}
