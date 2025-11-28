/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : test_memory.c                                                */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-27 17:38 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include <CUnit/CUnit.h>
#include <string.h>
#include "../include/libss.h"

void test_ss_memset()
{
	unsigned char buf1[10];
	ss_memset(buf1, 0xAA, sizeof(buf1));
	for (int i = 0; i < 10; i++) {
		CU_ASSERT(buf1[i] == 0xAA);
	}

	unsigned char buf2[5];
	unsigned char *ret = ss_memset(buf2, 0x55, 5);
	CU_ASSERT(ret == buf2);

	unsigned char buf3[4] = {1, 2, 3, 4};
	ss_memset(buf3, 0xFF, 0);
	CU_ASSERT(buf3[0] == 1);
	CU_ASSERT(buf3[1] == 2);
	CU_ASSERT(buf3[2] == 3);
	CU_ASSERT(buf3[3] == 4);

	unsigned char buf4[3];
	ss_memset(buf4, 0x1234, 3);
	CU_ASSERT(buf4[0] == 0x34);
	CU_ASSERT(buf4[1] == 0x34);
	CU_ASSERT(buf4[2] == 0x34);

	unsigned char buf5[8] = {0};
	ss_memset(buf5 + 2, 0x7F, 3);
	CU_ASSERT(buf5[0] == 0);
	CU_ASSERT(buf5[1] == 0);
	CU_ASSERT(buf5[2] == 0x7F);
	CU_ASSERT(buf5[3] == 0x7F);
	CU_ASSERT(buf5[4] == 0x7F);
	CU_ASSERT(buf5[5] == 0);
	CU_ASSERT(buf5[6] == 0);
	CU_ASSERT(buf5[7] == 0);

	unsigned char buf6[100];
	ss_memset(buf6, 0x00, 100);
	for (int i = 0; i < 100; i++) {
		CU_ASSERT(buf6[i] == 0);
	}

	unsigned char buf7[6] = {1,2,3,4,5,6};
	ss_memset(buf7 + 1, 0x11, 2);
	CU_ASSERT(buf7[0] == 1);
	CU_ASSERT(buf7[1] == 0x11);
	CU_ASSERT(buf7[2] == 0x11);
	CU_ASSERT(buf7[3] == 4);
	CU_ASSERT(buf7[4] == 5);
	CU_ASSERT(buf7[5] == 6);
}

void test_ss_bzero()
{
	unsigned char buf1[10];
	unsigned char cmp1[10];

	memset(buf1, 0xAA, 10);
	memset(cmp1, 0xAA, 10);

	ss_bzero(buf1, 10);
	memset(cmp1, 0, 10);

	for (int i = 0; i < 10; i++) {
		CU_ASSERT(buf1[i] == cmp1[i]);
	}

	unsigned char buf2[8]  = {1,2,3,4,5,6,7,8};
	unsigned char cmp2[8]  = {1,2,3,4,5,6,7,8};

	ss_bzero(buf2 + 2, 3);
	memset(cmp2 + 2, 0, 3);

	for (int i = 0; i < 8; i++) {
		CU_ASSERT(buf2[i] == cmp2[i]);
	}

	unsigned char buf3[5]  = {9,9,9,9,9};
	unsigned char cmp3[5]  = {9,9,9,9,9};

	ss_bzero(buf3, 0);
	memset(cmp3, 0, 0);

	for (int i = 0; i < 5; i++) {
		CU_ASSERT(buf3[i] == cmp3[i]);
	}

	unsigned char buf4[100];
	unsigned char cmp4[100];

	for (int i = 0; i < 100; i++) {
		buf4[i] = i + 1;
		cmp4[i] = i + 1;
	}

	ss_bzero(buf4, 100);
	memset(cmp4, 0, 100);

	for (int i = 0; i < 100; i++) {
		 CU_ASSERT(buf4[i] == cmp4[i]);
	}

	unsigned char buf5[8]  = {1,2,3,4,5,6,7,8};
	unsigned char cmp5[8]  = {1,2,3,4,5,6,7,8};

	ss_bzero(buf5 + 1, 2);
	memset(cmp5 + 1, 0, 2);

	for (int i = 0; i < 8; i++) {
		CU_ASSERT(buf5[i] == cmp5[i]);
	}
}

void test_ss_memchr()
{
	const unsigned char buf1[] = {1, 2, 3, 2, 1};
	CU_ASSERT(ss_memchr(buf1, 2, 5) == buf1 + 1);
	CU_ASSERT(ss_memchr(buf1, 3, 5) == buf1 + 2);

	CU_ASSERT(ss_memchr(buf1, 9, 5) == NULL);

	CU_ASSERT(ss_memchr(buf1, 1, 0) == NULL);

	const unsigned char buf2[] = {1, 0, 3, 0, 5};
	CU_ASSERT(ss_memchr(buf2, 0, 5) == buf2 + 1);

	const unsigned char buf3[] = {0xFF, 0x34, 0x80};

	CU_ASSERT(ss_memchr(buf3, -1, 3) == buf3 + 0);

	// 300 → 300 % 256 = 44 (0x2C)
	CU_ASSERT(ss_memchr(buf3, 300, 3) == NULL);

	// 0x1234 → 0x34
	CU_ASSERT(ss_memchr(buf3, 0x1234, 3) == buf3 + 1);

	const unsigned char buf4[] = {10, 20, 0, 30, 40};
	CU_ASSERT(ss_memchr(buf4, 30, 5) == buf4 + 3);

	const unsigned char buf5[] = {1, 2, 3, 4, 5};
	CU_ASSERT(ss_memchr(buf5 + 2, 4, 3) == buf5 + 3);

	const unsigned char buf6[] = {1, 2, 3, 4, 5, 6};
	for (int c = 0; c < 300; c++) {
		CU_ASSERT(ss_memchr(buf6, c, 6) == memchr(buf6, c, 6));
	}
}

void test_ss_memcpy()
{
	unsigned char src1[5] = {1,2,3,4,5};
	unsigned char dst1[5] = {0};
	unsigned char cmp1[5] = {0};

	ss_memcpy(dst1, src1, 5);
	memcpy(cmp1, src1, 5);

	for (int i = 0; i < 5; i++) {
		CU_ASSERT(dst1[i] == cmp1[i]);
	}

	unsigned char src2[8] = {10,20,30,40,50,60,70,80};
	unsigned char dst2[8] = {0};
	unsigned char cmp2[8] = {0};

	ss_memcpy(dst2 + 3, src2 + 1, 4);
	memcpy(cmp2 + 3, src2 + 1, 4);

	for (int i = 0; i < 8; i++) {
		CU_ASSERT(dst2[i] == cmp2[i]);
	}

	unsigned char src3[5] = {1, 0, 2, 0, 3};
	unsigned char dst3[5] = {0};
	unsigned char cmp3[5] = {0};

	ss_memcpy(dst3, src3, 5);
	memcpy(cmp3, src3, 5);

	for (int i = 0; i < 5; i++) {
		CU_ASSERT(dst3[i] == cmp3[i]);
	}

	unsigned char src4[3] = {9,9,9};
	unsigned char dst4[3] = {1,1,1};
	unsigned char cmp4[3] = {1,1,1};

	ss_memcpy(dst4, src4, 0);
	memcpy(cmp4, src4, 0);

	for (int i = 0; i < 3; i++) {
		CU_ASSERT(dst4[i] == cmp4[i]);
	}

	unsigned char src5[4] = {10, 20, 30, 40};
	unsigned char dst5[4] = {0};

	void *ret1 = ss_memcpy(dst5, src5, 4);
	void *ret2 = memcpy(dst5, src5, 4);

	CU_ASSERT(ret1 == dst5);
	CU_ASSERT(ret2 == dst5);

	unsigned char src6[6] = {1,2,3,4,5,6};
	unsigned char dst6[6];
	unsigned char cmp6[6];

	for (size_t len = 0; len <= 6; len++) {
		memset(dst6, 0xAA, 6);
		memset(cmp6, 0xAA, 6);

		ss_memcpy(dst6, src6, len);
		memcpy(cmp6, src6, len);

		for (int i = 0; i < 6; i++) {
			CU_ASSERT(dst6[i] == cmp6[i]);
		}
	}
}

void test_ss_memmove()
{
	unsigned char src1[6] = {1,2,3,4,5,6};
	unsigned char dst1[6] = {0};
	unsigned char cmp1[6] = {0};

	ss_memmove(dst1, src1, 6);
	memmove(cmp1, src1, 6);

	for (int i = 0; i < 6; i++)
		CU_ASSERT(dst1[i] == cmp1[i]);

	unsigned char buf2[10]  = {0,1,2,3,4,5,6,7,8,9};
	unsigned char cmp2[10]  = {0,1,2,3,4,5,6,7,8,9};

	ss_memmove(buf2 + 2, buf2, 6);
	memmove(cmp2 + 2, cmp2, 6);

	for (int i = 0; i < 10; i++)
		CU_ASSERT(buf2[i] == cmp2[i]);

	unsigned char buf3[10]  = {0,1,2,3,4,5,6,7,8,9};
	unsigned char cmp3[10]  = {0,1,2,3,4,5,6,7,8,9};

	ss_memmove(buf3, buf3 + 2, 6);
	memmove(cmp3, cmp3 + 2, 6);

	for (int i = 0; i < 10; i++)
		CU_ASSERT(buf3[i] == cmp3[i]);

	unsigned char buf4[5]  = {9,8,7,6,5};
	unsigned char cmp4[5]  = {9,8,7,6,5};

	ss_memmove(buf4, buf4, 5);
	memmove(cmp4, cmp4, 5);

	for (int i = 0; i < 5; i++)
		CU_ASSERT(buf4[i] == cmp4[i]);

	unsigned char src5[6] = {1,0,2,0,3,0};
	unsigned char dst5[6] = {9,9,9,9,9,9};
	unsigned char cmp5[6] = {9,9,9,9,9,9};

	ss_memmove(dst5, src5, 6);
	memmove(cmp5, src5, 6);

	for (int i = 0; i < 6; i++)
		CU_ASSERT(dst5[i] == cmp5[i]);

	unsigned char src6[3] = {1,2,3};
	unsigned char dst6[3] = {7,7,7};
	unsigned char cmp6[3] = {7,7,7};

	ss_memmove(dst6, src6, 0);
	memmove(cmp6, src6, 0);

	for (int i = 0; i < 3; i++)
		CU_ASSERT(dst6[i] == cmp6[i]);

	unsigned char src7[4] = {10,20,30,40};
	unsigned char dst7[4] = {0};

	void *ret1 = ss_memmove(dst7, src7, 4);
	CU_ASSERT(ret1 == dst7);

	unsigned char buf8[20];
	unsigned char cmp8[20];

	for (int i = 0; i < 20; i++)
	{
		buf8[i] = i;
		cmp8[i] = i;
	}

	for (size_t offset_dst = 0; offset_dst < 10; offset_dst++) {
		for (size_t offset_src = 0; offset_src < 10; offset_src++) {
			for (size_t len = 0; len <= 10; len++) {
				for (int i = 0; i < 20; i++) {
					buf8[i] = cmp8[i] = i;
				}

				ss_memmove(buf8 + offset_dst,
					buf8 + offset_src,
					len);

				memmove(cmp8 + offset_dst,
					cmp8 + offset_src,
					len);

				for (int i = 0; i < 20; i++)
					CU_ASSERT(buf8[i] == cmp8[i]);
			}
		}
	}
}

void test_ss_memcmp()
{
	unsigned char a1[] = {1,2,3,4,5};
	unsigned char b1[] = {1,2,3,4,5};

	CU_ASSERT(ss_memcmp(a1, b1, 5) == memcmp(a1, b1, 5));

	unsigned char a2[] = {1,2,3,4,5};
	unsigned char b2[] = {1,2,3,4,9};

	CU_ASSERT(ss_memcmp(a2, b2, 5) == memcmp(a2, b2, 5));

	unsigned char a3[] = {10,20,30,40};
	unsigned char b3[] = {10,20,31,40};

	CU_ASSERT(ss_memcmp(a3, b3, 4) == memcmp(a3, b3, 4));

	unsigned char a4[] = {1,0,2,0,3};
	unsigned char b4[] = {1,0,2,0,4};

	CU_ASSERT(ss_memcmp(a4, b4, 5) == memcmp(a4, b4, 5));

	unsigned char a5[] = {9,8,7};
	unsigned char b5[] = {1,2,3};

	CU_ASSERT(ss_memcmp(a5, b5, 0) == 0);
	CU_ASSERT(memcmp(a5, b5, 0) == 0);

	unsigned char a6[] = {200};
	unsigned char b6[] = {199};

	CU_ASSERT(ss_memcmp(a6, b6, 1) == memcmp(a6, b6, 1));

	unsigned char a7[] = {10};
	unsigned char b7[] = {100};

	CU_ASSERT(ss_memcmp(a7, b7, 1) == memcmp(a7, b7, 1));

	unsigned char a8[10];
	unsigned char b8[10];

	for (int i = 0; i < 10; i++) {
		a8[i] = i;
		b8[i] = i;
	}

	for (size_t len = 0; len <= 10; len++) {
		CU_ASSERT(ss_memcmp(a8, b8, len) == memcmp(a8, b8, len));
	}
}

