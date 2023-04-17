/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (c) 2023 AlanCui4080.
 */
#ifndef __NEKOXX_TEST_INC__
#define __NEKOXX_TEST_INC__

#include <stdio.h>

enum __teststatus {
	UNINIT = 0,
	TEST_RUNNING,
	TEST_FAILED,
	TEST_PASSED,
	META_BROKEN,
	FATAL_ERROR,

	MAX_STATUS
};

struct __testsuite {
	unsigned int status;
	unsigned long long count;
};
#define INIT_TEST() struct __testsuite __thistest = { 0 };
#define END_TEST()                                     \
	__thistest.status = __teststatus::TEST_PASSED; \
	return 0
#define TEST_START(v)                                   \
	__thistest.status = __teststatus::TEST_RUNNING; \
	__thistest.count++
#define TEST_FAIL(v)                                                          \
	__thistest.status = __teststatus::TEST_FAILED;                        \
	printf("Test %llu %s%s%s%llu%s%s%s", __thistest.count, "Failed @",    \
	       __FILE__, ":", (unsigned long long)__LINE__, " - ", #v, "\n"); \
	return __thistest.count

#define TEST_GOOD(v)

#define _TEST_FALSE(v)        \
	TEST_START(v);        \
	if (v) {              \
		TEST_FAIL(v); \
	} else {              \
		TEST_GOOD(v); \
	}
#define _TEST_TRUE(v)         \
	TEST_START(v);        \
	if (!v) {             \
		TEST_FAIL(v); \
	} else {              \
		TEST_GOOD(v); \
	}

#define TEST_FALSE(v) _TEST_FALSE((v))
#define TEST_TRUE(v) _TEST_TRUE((v))

#endif //__NEKOXX_TEST_INC__
