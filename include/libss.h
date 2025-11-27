/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : libss.h                                                      */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 16:21 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#ifndef LIBSS_H
#define LIBSS_H

#include <unistd.h>

/* ctype functions */
int ss_isdigit(int c);

/* memory functions */

/* test functions */
void test_ss_isdigit();

#endif
