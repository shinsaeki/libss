/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_memcmp.c                                                  */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 11:39 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

int ss_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *uc_s1 = s1;
	const unsigned char *uc_s2 = s2;

	while(n--)
	{
		if (*uc_s1 != *uc_s2)
			return (int)(*uc_s1 - *uc_s2);
		uc_s1++;
		uc_s2++;
	}
	return 0;
}
