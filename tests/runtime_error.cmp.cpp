#include<cstdio>
#include<new>
#include<nekoexception>
#include<exception>
#include<stdexcept>

void f2()
{
	__nthrow(std::runtime_error("This is a runtime error"));
}

void f1()
{
	f2();
}

int main()
{
	__ntry
		f2();
	__ncatch(e)
		std::puts(e.what());
	__netry
	return 0;
}
