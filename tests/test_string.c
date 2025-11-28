/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : test_string.c                                                */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 17:38 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include <CUnit/CUnit.h>
#include <string.h>
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

void test_ss_strchr()
{
	const char *s = "hello world";

	CU_ASSERT(ss_strchr(s, 'h') == s);            
	CU_ASSERT(ss_strchr(s, 'e') == s + 1);        
	CU_ASSERT(ss_strchr(s, 'l') == s + 2);       

	CU_ASSERT(ss_strchr(s, 'o') == s + 4);       

	CU_ASSERT(ss_strchr(s, 'x') == NULL);

	CU_ASSERT(ss_strchr("", 'a') == NULL);

	CU_ASSERT(ss_strchr(s, '\0') == s + 11);     

	const char *t = "abcabc";
	CU_ASSERT(ss_strchr(t, 'b') == t + 1);
	CU_ASSERT(ss_strchr(t, 'c') == t + 2);
	CU_ASSERT(ss_strchr(t, 'a') == t);           

	const char u[] = {'a', 'b', '\0', 'c', 'd'};
	CU_ASSERT(ss_strchr(u, 'c') == NULL);        

	CU_ASSERT(ss_strchr("A\xFF", 255) == NULL);  
}

void test_ss_strrchr()
{
	const char *s = "hello world";

	CU_ASSERT(ss_strrchr(s, 'l') == s + 9);     
	CU_ASSERT(ss_strrchr(s, 'o') == s + 7);     

	CU_ASSERT(ss_strrchr(s, 'h') == s);         

	CU_ASSERT(ss_strrchr(s, 'x') == NULL);

	CU_ASSERT(ss_strrchr("", 'a') == NULL);

	CU_ASSERT(ss_strrchr(s, '\0') == s + 11);  

	const char *t = "abcabc";
	CU_ASSERT(ss_strrchr(t, 'a') == t + 3);     
	CU_ASSERT(ss_strrchr(t, 'b') == t + 4);
	CU_ASSERT(ss_strrchr(t, 'c') == t + 5);

	const char u[] = {'x', 'y', '\0', 'a', 'b'};
	CU_ASSERT(ss_strrchr(u, 'a') == NULL);      

	CU_ASSERT(ss_strrchr("A", 'A') != NULL);
	CU_ASSERT(ss_strrchr("A", 'B') == NULL);

	CU_ASSERT(ss_strrchr("XYZ", 'Z') == "XYZ" + 2);

	CU_ASSERT(ss_strrchr("A\xFF", 255) == NULL);
}

void test_ss_strlcpy()
{
	char dst1[20];
	char dst2[20];

	memset(dst1, 'X', sizeof(dst1));
	memset(dst2, 'X', sizeof(dst2));

	size_t r1 = ss_strlcpy(dst1, "HELLO", sizeof(dst1));
	size_t r2 = strlcpy(dst2, "HELLO", sizeof(dst2));

	CU_ASSERT(r1 == r2);
	CU_ASSERT_STRING_EQUAL(dst1, dst2);

	char d3[4], d4[4];
	memset(d3, 'X', 4);
	memset(d4, 'X', 4);

	size_t r3 = ss_strlcpy(d3, "ABCDEFG", 4);
	size_t r4 = strlcpy(d4, "ABCDEFG", 4);

	CU_ASSERT(r3 == r4);
	CU_ASSERT_STRING_EQUAL(d3, d4);
	CU_ASSERT(d3[3] == '\0');

	char d5[5] = "AAAA";
	char d6[5] = "AAAA";

	size_t r5 = ss_strlcpy(d5, "HELLO", 1);
	size_t r6 = strlcpy(d6, "HELLO", 1);

	CU_ASSERT(r5 == r6);
	CU_ASSERT(d5[0] == '\0');

	char d7[5] = "ZZZZ";
	char d8[5] = "ZZZZ";

	size_t r7 = ss_strlcpy(d7, "ABC", 0);
	size_t r8 = strlcpy(d8, "ABC", 0);

	CU_ASSERT(r7 == r8);
	CU_ASSERT(memcmp(d7, d8, 5) == 0);

	char d9[10] = "XXXXXXXXX";
	char d10[10] = "XXXXXXXXX";

	size_t r9 = ss_strlcpy(d9, "", sizeof(d9));
	size_t r10 = strlcpy(d10, "", sizeof(d10));

	CU_ASSERT(r9 == r10);
}

void test_ss_strlcat()
{
	{
		char a[30] = "HELLO";
		char b[30] = "HELLO";

		size_t ra = ss_strlcat(a, "WORLD", sizeof(a));
		size_t rb = strlcat(b, "WORLD", sizeof(b));

		CU_ASSERT(ra == rb);
		CU_ASSERT_STRING_EQUAL(a, b);
	}
	
	{
		char a[10] = "HELLO";   // len = 5
		char b[10] = "HELLO";

		size_t ra = ss_strlcat(a, "WORLD", sizeof(a));
		size_t rb = strlcat(b, "WORLD", sizeof(b));

		CU_ASSERT(ra == rb);     
		CU_ASSERT(memcmp(a, b, 10) == 0);
	}

	{
		char a[5] = "AAAA";
		char b[5] = "AAAA";

		size_t ra = ss_strlcat(a, "BBB", 0);
		size_t rb = strlcat(b, "BBB", 0);

		CU_ASSERT(ra == rb);        // dstsize + strlen(src)
		CU_ASSERT(memcmp(a, b, 5) == 0);
	}

	{
		char a[5] = "HELLO";
		char b[5] = "HELLO";

		size_t ra = ss_strlcat(a, "XYZ", 1);
		size_t rb = strlcat(b, "XYZ", 1);

		CU_ASSERT(ra == rb);
		CU_ASSERT(memcmp(a, b, 5) == 0);
	}

	{
		char a[5] = "AAAA";
		char b[5] = "AAAA";

		size_t ra = ss_strlcat(a, "BBBBBBB", 3); // strlen(a)=4 >= dstsize=3
		size_t rb = strlcat(b, "BBBBBBB", 3);

		CU_ASSERT(ra == rb);
		CU_ASSERT(memcmp(a, b, 5) == 0);
	}

	{
		char a[20] = "TEST";
		char b[20] = "TEST";

		size_t ra = ss_strlcat(a, "", sizeof(a));
		size_t rb = strlcat(b, "", sizeof(b));

		CU_ASSERT(ra == rb);
		CU_ASSERT_STRING_EQUAL(a, b);
	}

	{
		char a[20] = "";
		char b[20] = "";

		size_t ra = ss_strlcat(a, "ABC", sizeof(a));
		size_t rb = strlcat(b, "ABC", sizeof(b));

		CU_ASSERT(ra == rb);
		CU_ASSERT_STRING_EQUAL(a, b);
	}

	{
		char src[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";  // 26 bytes

		for (size_t sz = 0; sz <= 30; sz++) {
			char a[50] = "HELLO";
			char b[50] = "HELLO";

			size_t ra = ss_strlcat(a, src, sz);
			size_t rb = strlcat(b, src, sz);

			CU_ASSERT(ra == rb);
			CU_ASSERT(memcmp(a, b, 50) == 0);
		}
	}
}
