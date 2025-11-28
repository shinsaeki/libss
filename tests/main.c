/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : main.c                                                       */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 16:32 JS                                          */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../include/libss.h"

int main()
{
	CU_initialize_registry();

	CU_pSuite suite_ctype = CU_add_suite("libss ctypes tests", NULL, NULL);
	CU_add_test(suite_ctype, "test ss_isdigit", test_ss_isdigit);
	CU_add_test(suite_ctype, "test_ss_isalpha", test_ss_isalpha);
	CU_add_test(suite_ctype, "test_ss_isalnum", test_ss_isalnum);
	CU_add_test(suite_ctype, "test_ss_isascii", test_ss_isascii);
	CU_add_test(suite_ctype, "test_ss_isprint", test_ss_isprint);
	CU_add_test(suite_ctype, "test_ss_toupper", test_ss_toupper);
	CU_add_test(suite_ctype, "test_ss_tolower", test_ss_tolower);

	CU_pSuite suite_string = CU_add_suite("libss string tests", NULL, NULL);
	CU_add_test(suite_string, "test ss_strlen", test_ss_strlen);
	CU_add_test(suite_string, "test ss_strnlen", test_ss_strnlen);
	CU_add_test(suite_string, "test ss_strchr", test_ss_strchr);
	CU_add_test(suite_string, "test ss_strrchr", test_ss_strrchr);
	CU_add_test(suite_string, "test ss_strlcpy", test_ss_strlcpy);
	CU_add_test(suite_string, "test ss_strlcat", test_ss_strlcat);
	CU_add_test(suite_string, "test ss_strnstr", test_ss_strnstr);
	CU_add_test(suite_string, "test ss_atoi", test_ss_atoi);
	CU_add_test(suite_string, "test ss_strdup", test_ss_strdup);

	CU_pSuite suite_memory = CU_add_suite("libss memory tests", NULL, NULL);
	CU_add_test(suite_memory, "test ss_memset", test_ss_memset);
	CU_add_test(suite_memory, "test ss_bzero", test_ss_bzero);
	CU_add_test(suite_memory, "test ss_memchr", test_ss_memchr);
	CU_add_test(suite_memory, "test ss_memcpy", test_ss_memcpy);
	CU_add_test(suite_memory, "test ss_memmove", test_ss_memmove);
	CU_add_test(suite_memory, "test ss_memcmp", test_ss_memcmp);
	CU_add_test(suite_memory, "test ss_calloc", test_ss_calloc);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

	return 0;
}
