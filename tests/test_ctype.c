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

void test_ss_isalnum()
{
	for (int c = '0'; c <= '9'; c++)
		CU_ASSERT(ss_isalnum(c) == 1);

	for (int c = 'A'; c <= 'Z'; c++)
		CU_ASSERT(ss_isalnum(c) == 1);

	for (int c = 'a'; c <= 'z'; c++)
		CU_ASSERT(ss_isalnum(c) == 1);

	CU_ASSERT(ss_isalnum('/' /* 0x2F */) == 0);
	CU_ASSERT(ss_isalnum(':' /* 0x3A */) == 0);

	CU_ASSERT(ss_isalnum('@' /* 0x40 */) == 0);
	CU_ASSERT(ss_isalnum('[' /* 0x5B */) == 0);

	CU_ASSERT(ss_isalnum('`' /* 0x60 */) == 0);
	CU_ASSERT(ss_isalnum('{' /* 0x7B */) == 0);

	char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', ' '};
	for (int i = 0; i < sizeof(symbols) / sizeof(char); i++)
		CU_ASSERT(ss_isalnum(symbols[i]) == 0);

	char ext[] = { '\xFF', '\xFE', '\xFD', 0 };
	for (int i = 0; i < 3; i++)
		CU_ASSERT(ss_isalnum(ext[i]) == 0);

	CU_ASSERT(ss_isalnum(-1) == 0);
}

void test_ss_isascii()
{
	for (int c = 0; c <= 127; c++) {
		CU_ASSERT(ss_isascii(c) == 1);
	}

	int invalid[] = { -1, -10, 128, 129, 200, 255, 300 };
	int size = sizeof(invalid) / sizeof(invalid[0]);

	for (int i = 0; i < size; i++) {
		CU_ASSERT(ss_isascii(invalid[i]) == 0);
	}
}

void test_ss_isprint()
{
	for (int c = 0x20; c <= 0x7e; c++) {
		CU_ASSERT(ss_isprint(c) == 1);
	}

	for (int c = 0; c < 0x20; c++) {
		CU_ASSERT(ss_isprint(c) == 0);
	}

	CU_ASSERT(ss_isprint(0x7f) == 0);

	int invalid[] = {128, 200, 255, 300, -1, -20};
	int size = sizeof(invalid) / sizeof(invalid[0]);

	for (int i = 0; i < size; i++) {
		CU_ASSERT(ss_isprint(invalid[i]) == 0);
	}
}

void test_ss_toupper()
{
	for (int c = 'a'; c <= 'z'; c++) {
		CU_ASSERT(ss_toupper(c) == (c - 32));
	}

	for (int c = 'A'; c <= 'Z'; c++) {
		CU_ASSERT(ss_toupper(c) == c);
	}

	int symbols[] = {'0', '9', '+', '-', '/', '@', '~', ' ', '\t'};
	int symbols_size = sizeof(symbols) / sizeof(symbols[0]);

	for (int i = 0; i < symbols_size; i++) {
		CU_ASSERT(ss_toupper(symbols[i]) == symbols[i]);
	}

	int ascii_extended[] = {128, 150, 200, 255};
	int ext_size = sizeof(ascii_extended) / sizeof(ascii_extended[0]);

	for (int i = 0; i < ext_size; i++) {
		CU_ASSERT(ss_toupper(ascii_extended[i]) == ascii_extended[i]);
	}

	int negative_values[] = {-1, -5, -128};
	int neg_size = sizeof(negative_values) / sizeof(negative_values[0]);

	for (int i = 0; i < neg_size; i++) {
		CU_ASSERT(ss_toupper(negative_values[i]) == negative_values[i]);
	}
}

void test_ss_tolower()
{
	for (int c = 'A'; c <= 'Z'; c++) {
		CU_ASSERT(ss_tolower(c) == (c + 32));
	}

	for (int c = 'a'; c <= 'z'; c++) {
		CU_ASSERT(ss_tolower(c) == c);
	}

	int symbols[] = {'0', '9', '+', '-', '/', '@', '~', ' ', '\t'};
	int symbols_size = sizeof(symbols) / sizeof(symbols[0]);

	for (int i = 0; i < symbols_size; i++) {
		CU_ASSERT(ss_tolower(symbols[i]) == symbols[i]);
	}

	int ascii_extended[] = {128, 150, 200, 255};
	int ext_size = sizeof(ascii_extended) / sizeof(ascii_extended[0]);

	for (int i = 0; i < ext_size; i++) {
		CU_ASSERT(ss_tolower(ascii_extended[i]) == ascii_extended[i]);
	}
	
	int negative_values[] = {-1, -5, -100};
	int neg_size = sizeof(negative_values) / sizeof(negative_values[0]);

	for (int i = 0; i < neg_size; i++) {
		CU_ASSERT(ss_tolower(negative_values[i]) == negative_values[i]);
	}
}
