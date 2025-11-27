/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_isprint.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 18:28 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

int ss_isprint(int c)
{
	return 32 <= c && c <= 126;
}
