/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (c) 2023 Ziyao.
 */

#include<nekoexception>
#include<exception>
#include<stdexcept>
#include<new>

#include<bits/libnekoxx>

namespace std {
	runtime_error::runtime_error(const char *what_arg)
	{
		this->count	= new int;
		this->msg	= __libnekoxx::strdup(what_arg);
		if (!this->msg) {
			delete this->count;
			__nthrow(std::bad_alloc());
		}
		*(this->count) = 1;
	}

	void runtime_error::dec_ref() noexcept
	{
		*(this->count)--;
		if (!this->count) {
			__libnekoxx::free(this->msg);
			delete this->count;
		}
	}

	void runtime_error::copy(const runtime_error &other) noexcept
	{
		this->count	= other.count;
		this->msg	= other.msg;
		*(this->count)++;
	}
};
