#include<stdio.h>

class foo {
public:
	foo()
	{
		puts("Created");
	}

	~foo()
	{
		puts("Destroyed");
	}
};

class foo f;

int main()
{
	return 0;
}
