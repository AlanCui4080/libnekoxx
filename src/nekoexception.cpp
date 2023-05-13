/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (c) 2023 Ziyao.
 */

#include <setjmp.h>

#include <bits/nekoexception>

jmp_buf __nekoTryEnv;
void   *__nekoExceptionObj;
