/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (c) 2023 Ziyao.
 */

#include <bits/libnekoxx>

extern "C" {

#define __NEKOXX_DESTRUCTOR_MAX_NUM__ 256

#include <stdlib.h>

static int inited;
static struct {
	void (*f)(void *);
	void *a;
	void *d;
} destructors[__NEKOXX_DESTRUCTOR_MAX_NUM__];
static int count;

void *__dso_handle __NEKOXX_HIDDEN__ __NEKOXX_WEAK__ = 0;

void __cxa_finalize(void *d)
{
	/*	Destrory everything	*/
	if (!d) {
		for (int i = 0; i < count; i++) {
			if (destructors[i].f) {
				void (*f)(void *) = destructors[i].f;
				destructors[i].f = 0;
				f(destructors[i].a);
			}
		}
		return;
	}

	for (int i = 0; i < count; i++) {
		if (destructors[i].f && destructors[i].d == d) {
			void (*f)(void *) = destructors[i].f;
			destructors[i].f = 0;
			f(destructors[i].a);
		}
	}
	return;
}

static void exit_handler()
{
	__cxa_finalize(0);
	return;
}

int __cxa_atexit(void (*destructor)(void *), void *arg, void *dso)
{
	if (!inited) {
		inited = 1;
		atexit(exit_handler);
	}

	int i = count;
	if (i >= __NEKOXX_DESTRUCTOR_MAX_NUM__)
		return -1;

	destructors[i].f = destructor;
	destructors[i].a = arg;
	destructors[i].d = dso;
	count = i + 1;

	return 0;
}
};
