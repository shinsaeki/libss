/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : test_additional.c                                            */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 21:11 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include <CUnit/CUnit.h>
#include <string.h>
#include <limits.h>
#include "../include/libss.h"

void test_ss_substr()
{
	{
		char *res = ss_substr("HelloWorld", 0, 5);
		CU_ASSERT_PTR_NOT_NULL(res);
		CU_ASSERT_STRING_EQUAL(res, "Hello");
		free(res);
	}

	{
		char *res = ss_substr("HelloWorld", 5, 5);
		CU_ASSERT_PTR_NOT_NULL(res);
		CU_ASSERT_STRING_EQUAL(res, "World");
		free(res);
	}

	{
		char *res = ss_substr("HelloWorld", 7, 10);
		CU_ASSERT_PTR_NOT_NULL(res);
		CU_ASSERT_STRING_EQUAL(res, "rld");
		free(res);
	}

	{
		char *res = ss_substr("ABCDE", 5, 10);  // len_s = 5
		CU_ASSERT_PTR_NOT_NULL(res);
		CU_ASSERT_STRING_EQUAL(res, "");
		free(res);
	}

	{
		char *res = ss_substr("ABCDE", 100, 3);
		CU_ASSERT_PTR_NOT_NULL(res);
		CU_ASSERT_STRING_EQUAL(res, "");
		free(res);
	}

	{
		char *res = ss_substr("ABCDE", 2, 0);
		CU_ASSERT_PTR_NOT_NULL(res);
		CU_ASSERT_STRING_EQUAL(res, "");
		free(res);
	}

	{
		char *res = ss_substr("ABCDE", 3, 1);
		CU_ASSERT_PTR_NOT_NULL(res);
		CU_ASSERT_STRING_EQUAL(res, "D");
		free(res);
	}

	{
		char *res = ss_substr("ABCDE", 0, 100);
		CU_ASSERT_PTR_NOT_NULL(res);
		CU_ASSERT_STRING_EQUAL(res, "ABCDE");
		free(res);
	}

	{
		char *res = ss_substr("", 0, 10);
		CU_ASSERT_PTR_NOT_NULL(res);
		CU_ASSERT_STRING_EQUAL(res, "");
		free(res);
	}

	{
		char *res = ss_substr(NULL, 0, 5);
		CU_ASSERT_PTR_NULL(res);
	}

	{
		char src[] = "HelloWorld";
		char *res = ss_substr(src, 0, 5);
		src[0] = 'Z';
		CU_ASSERT_STRING_EQUAL(res, "Hello");
		free(res);
	}

	{
		char *res = ss_substr("ABCDE", 1, 2);  // "BC"
		CU_ASSERT(res[2] == '\0');
		free(res);
	}

	{
		char big[1024];
		for (int i = 0; i < 1023; i++)
			big[i] = 'A';
		big[1023] = '\0';

		char *res = ss_substr(big, 100, 50);
		CU_ASSERT_PTR_NOT_NULL(res);

		for (int i = 0; i < 50; i++)
			CU_ASSERT(res[i] == 'A');

		CU_ASSERT(res[50] == '\0');

		free(res);
	}
}
