/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : isdigit.c                                                    */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 16:07 J                                           */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "libss.h"

int ss_isdigit(int c)
{
	return '0' <= c && c <= '9';
}
