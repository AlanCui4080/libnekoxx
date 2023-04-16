/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (c) 2023 Ziyao.
 */

#include<setjmp.h>

#include<nekoexception>

jmp_buf __nekoTryEnv;
std::exception __nekoExceptionObj;
int __nekoTryTop;
