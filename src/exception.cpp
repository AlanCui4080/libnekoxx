/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (C) 2023 Ziyao.
 */

#include <stdlib.h>

#include <exception>

namespace std
{
	void terminate() noexcept
	{
		abort();
	}
}; // namespace std
