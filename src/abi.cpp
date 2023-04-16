/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (c) 2023 Ziyao.
 */

extern "C" {

#include<stdlib.h>

static int inited;
static struct {
	void (*destructor) (void *);
	void *arg;
	void *dso;
} destructorList[256];
static int destructorCount;

void *__dso_handle = (void*)0;

void __cxa_finalize(void *f)
{
	if (f) {
		for (int i = 0; i < destructorCount; i++) {
			if (destructorList[i].destructor == f) {
				destructorList[i].destructor = 0;
				return;
			}
		}
	}

	for (int i = 0; i < destructorCount; i++) {
		if (destructorList[i].destructor)
			destructorList[i].destructor(destructorList[i].arg);
	}
	return;
}

static void exit_handler()
{
	__cxa_finalize(0);
	return;
}

int __cxa_atexit(void (*destructor) (void *), void *arg, void *dso)
{
	if (!inited) {
		inited = 1;
		atexit(exit_handler);
	}

	int i = destructorCount;
	destructorList[i].destructor	= destructor;
	destructorList[i].arg		= arg;
	destructorList[i].dso		= dso;
	destructorCount = i + 1;

	return 0;
}

};
