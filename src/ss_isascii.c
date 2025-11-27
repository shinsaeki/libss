/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_isascii.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 18:17 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

int ss_isascii(int c)
{
	return 0 <= c && c <= 127;
}
