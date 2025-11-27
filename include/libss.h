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
int ss_isalpha(int c);

/* string functions */
size_t ss_strlen(const char *s);
size_t ss_strnlen(const char *s, size_t maxlen);

/* memory functions */

/* test functions */
void test_ss_isdigit();
void test_ss_isalpha();
void test_ss_strlen();
void test_ss_strnlen();

#endif
