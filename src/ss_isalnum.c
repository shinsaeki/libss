/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_isalnum.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 18:07 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

int ss_isalnum(int c)
{
	return ss_isalpha(c) || ss_isdigit(c);
}
