/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_bzero.c                                                   */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 22:24 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

void ss_bzero(void *s, size_t n)
{
	ss_memset(s, 0, n);
}
