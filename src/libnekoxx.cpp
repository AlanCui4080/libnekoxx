/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (c) 2023 Ziyao.
 */

/*	Internal tools	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bits/libnekoxx>

namespace __libnekoxx
{
	void *malloc(size_t size)
	{
		return ::malloc(size);
	}

	void free(void *p)
	{
		::free(p);
	}

	void *realloc(void *p, size_t size)
	{
		return ::realloc(p, size);
	}

	char *strdup(const char *src)
	{
		char *copy = (char *)malloc(strlen(src) + 1);
		return copy ? strcpy(copy, src) : copy;
	}
}; // namespace __libnekoxx
