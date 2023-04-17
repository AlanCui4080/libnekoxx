/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (c) 2023 Ziyao.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <nekoexception>
#include <new>

#include <bits/libnekoxx>

void * operator new (size_t count, void *p)
{
	return p;
}

void * operator new [] (size_t count, void *p)
{
	return p;
}

void * operator new (size_t count)
{
	void *p = __libnekoxx::malloc(count);
	if (!p)
		__nthrow(std::bad_alloc());
	return p;
}

void * operator new [] (size_t count)
{
	void *p = __libnekoxx::malloc(count);
	if (!p)
		__nthrow(std::bad_alloc());
	return p;
}

void operator delete(void *p) noexcept
{
	__libnekoxx::free(p);
}

void operator delete[](void *p) noexcept
{
	__libnekoxx::free(p);
}

void operator delete(void *p, size_t size) noexcept
{
	__libnekoxx::free(p);
}

void operator delete[](void *p, size_t size) noexcept
{
	(void)size;
	__libnekoxx::free(p);
}
