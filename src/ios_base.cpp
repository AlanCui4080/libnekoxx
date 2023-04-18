/*
 *	libnekoxx
 *	By MIT License.
 *	Copyright (c) 2023 Ziyao.
 */

#include<ios>

namespace std {
	int ios_base::xalloc()
	{
		return ios_base::index++;
	}

	long int &ios_base::iword(int index)
	{
		if (ios_base::isize <= index) {
			ios_base::iwords =
				(long int*)realloc((void*)ios_base::iwords,
						   sizeof(long int) * index);
			isize = index + 1;
		}
		return ios_base::iwords[index];
	}

	void *&ios_base::pword(int index)
	{
		if (ios_base::psize <= index) {
			ios_base::pwords =
				(void**)realloc((void*)ios_base::pwords,
						sizeof(long int) * index);
			psize = index + 1;
		}
		return ios_base::pwords[index];
	}

	ios_base::Init::Init() {};
	ios_base::Init::~Init() {};

	int ios_base::index;
	long int *ios_base::iwords;
	void **ios_base::pwords;
	size_t ios_base::isize, ios_base::psize;
};
