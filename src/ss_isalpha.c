/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_isalpha.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 17:14 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

int ss_isalpha(int c)
{
	return ('A' <= c && c <= 'Z') || ('a' <= c && c<= 'z');
}
