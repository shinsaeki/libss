/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : test_ctype.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 16:18 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include <CUnit/CUnit.h>
#include "libss.h"

void test_ss_isdigit()
{
	for (int c = '0'; c <= '9'; c++) CU_ASSERT(ss_isdigit(c) == 1);

	int invalid[] = {'a', 'A', '/', ' ', '&', -1, 200};
	for (int i = 0; i < sizeof(invalid) / sizeof(int); i++)
	{
		CU_ASSERT(ss_isdigit(invalid[i]) == 0);
	}
}

void test_ss_isalpha()
{
	for (int c = 'A'; c <= 'Z'; c++) CU_ASSERT(ss_isalpha(c) == 1);
	for (int c = 'a'; c <= 'z'; c++) CU_ASSERT(ss_isalpha(c) == 1);

	int invalid[] = {'1', '/', ' ', '&', -1};
	for (int i = 0; i <= sizeof(invalid) / sizeof(int); i++)
	{
		CU_ASSERT(ss_isalpha(invalid[i]) == 0);
	}
}
