#include <stdio.h>
#include <nekoexception>
#include <exception>
#include <new>

int main()
{
	__ntry char *s = new char[1145141919810 * 114];
	__ncatch(e) puts(e.what());
	__netry

		char *s = new char[16];
	s[0] = 0;
	delete[] s;
	return 0;
}
