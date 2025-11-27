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

	CU_pSuite suite_string = CU_add_suite("libss ctypes tests", NULL, NULL);
	CU_add_test(suite_string, "test ss_strlen", test_ss_strlen);
	CU_add_test(suite_string, "test ss_strnlen", test_ss_strnlen);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	CU_cleanup_registry();

	return 0;
}
