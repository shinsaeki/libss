/* ===================================================================== */
/*                         l i b s s   (L I B C)                         */
/* --------------------------------------------------------------------- */
/* File   : ss_strnstr.c                                                 */
/* Author : Shintaro Saeki                                               */
/* Created: 2025-11-28 14:30 JST                                         */
/* Desc   : A minimal re-implementation of core libc utilities.          */
/* ===================================================================== */

#include "../include/libss.h"

char *ss_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return haystack;

	size_t i = 0;
	while (i < len && haystack[i])
	{
		size_t j = 0;
		if (haystack[i] == needle[j])
		{
			while(i + j < len && needle[j] && haystack[i + j] == needle[j])
				j++;
			if(needle[j] == '\0')
				return (char *)(haystack + i);
		}
		i++;
	}
	return NULL;
}
