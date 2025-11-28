/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_isspace.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 19:35 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

int ss_isspace(int c)
{
	return (c == ' ') || (c == '\t') || (c == '\n')
			|| (c == '\v') || (c == '\f') || (c == '\r');
}
