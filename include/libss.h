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
#include <stdlib.h>

/* ctype functions */
int ss_isdigit(int c);
int ss_isalpha(int c);
int ss_isalnum(int c);
int ss_isascii(int c);
int ss_isprint(int c);
int ss_isspace(int c);
int ss_toupper(int c);
int ss_tolower(int c);

/* string functions */
size_t ss_strlen(const char *s);
size_t ss_strnlen(const char *s, size_t maxlen);
char *ss_strchr(const char *s, int c);
char *ss_strrchr(const char *s, int c);
size_t ss_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
size_t ss_strlcat(char *restrict dst, const char *restrict src, size_t dstsize);
char* ss_strnstr(const char *haystack, const char *needle, size_t len);
int ss_atoi(const char *str);
char *ss_strdup(const char *s1);

/* memory functions */
void *ss_memset(void *b, int c, size_t len);
void ss_bzero(void *s, size_t n);
void *ss_memchr(const void *s, int c, size_t n);
void *ss_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *ss_memmove(void *dst, const void *src, size_t n);
int ss_memcmp(const void *s1, const void *s2, size_t n);
void *ss_calloc(size_t count, size_t size);

/* test functions */
void test_ss_isdigit();
void test_ss_isalpha();
void test_ss_isalnum();
void test_ss_isascii();
void test_ss_isprint();
void test_ss_toupper();
void test_ss_tolower();
void test_ss_strlen();
void test_ss_strnlen();
void test_ss_strchr();
void test_ss_strrchr();
void test_ss_strlcpy();
void test_ss_strlcat();
void test_ss_strnstr();
void test_ss_atoi();
void test_ss_strdup();
void test_ss_memset();
void test_ss_bzero();
void test_ss_memchr();
void test_ss_memcpy();
void test_ss_memmove();
void test_ss_memcmp();
void test_ss_calloc();

#endif
