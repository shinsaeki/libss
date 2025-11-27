/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_toupper.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 19:24 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

int ss_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return c - ('a' - 'A');
	return c;
}
