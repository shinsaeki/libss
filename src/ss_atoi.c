/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_atoi.c                                                    */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 19:31 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

int ss_atoi(const char *str)
{
	int sign = 1;
	int n = 0;

	while(ss_isspace(*str))
		str++;

	if (*str == '+' || *str == '-')
	{
		if (*str == '-') sign = -1;
		str++;
	}

	while ('0' <= *str && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return sign * n;
}
