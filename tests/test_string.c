/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : test_string.c                                                */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 17:38 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include <CUnit/CUnit.h>
#include "../include/libss.h"

void test_ss_strlen()
{
	/* basic cases */
	CU_ASSERT(ss_strlen("") == 0);
	CU_ASSERT(ss_strlen("a") == 1);
	CU_ASSERT(ss_strlen("hello") == 5);

	/* including space or symbol */
	CU_ASSERT(ss_strlen(" ") == 1);
	CU_ASSERT(ss_strlen("abc def") == 7);
	CU_ASSERT(ss_strlen("123!@#") == 6);

	/* long string */
	CU_ASSERT(ss_strlen("abcdefghijklmnopqrstuvwxyz") == 26);

	/* check NULL symbol */
	char with_null[] = {'a', 'b', '\0', 'c', 'd'};
	CU_ASSERT(ss_strlen(with_null) == 2);

	/* escape */
	CU_ASSERT(ss_strlen("a\nb\nc") == 5);
	CU_ASSERT(ss_strlen("tab\ttest") == 8);

	/* extended ASCII */
	char ext[] = { '\xFF', '\xFE', '\xFD', '\0' };
	CU_ASSERT(ss_strlen(ext) == 3);
}

void test_ss_strnlen()
{
	CU_ASSERT(ss_strnlen("", 10) == 0);
	CU_ASSERT(ss_strnlen("abc", 10) == 3);
	CU_ASSERT(ss_strnlen("hello", 5) == 5);

	CU_ASSERT(ss_strnlen("abcdef", 3) == 3);
	CU_ASSERT(ss_strnlen("abcdef", 0) == 0);

	char with_null[] = {'a', 'b', '\0', 'c', 'd'};
	CU_ASSERT(ss_strnlen(with_null, 10) == 2);
	CU_ASSERT(ss_strnlen(with_null, 2) == 2);
	CU_ASSERT(ss_strnlen(with_null, 1) == 1);

	CU_ASSERT(ss_strnlen("abc", 1000) == 3);

	CU_ASSERT(ss_strnlen("a b c", 10) == 5);
	CU_ASSERT(ss_strnlen("!@#$%", 3) == 3);
	CU_ASSERT(ss_strnlen("!@#$%", 10) == 5);
    
	char ext[] = { '\xFF', '\xFE', '\xFD', '\0' };
	CU_ASSERT(ss_strnlen(ext, 10) == 3);
	CU_ASSERT(ss_strnlen(ext, 2) == 2);
}
