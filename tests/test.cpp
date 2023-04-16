#include<stdio.h>
#include<nekoexception>
#include<exception>
#include<new>

int main()
{
	__ntry
		char *s = new char[1145141919810 * 114];
	__nscatch(std::exception, e)
		puts(e.what());
	__necatch
	return 0;
}
