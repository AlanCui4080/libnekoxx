#include<stdio.h>
#include<memory>

int main()
{
	std::allocator<int> alloc1;
	std::allocator<char> alloc2;

	int *i = alloc1.allocate(1);
	char *c = alloc2.allocate(1);

	printf("%d\n", (int)(alloc1 == alloc2));
	printf("%p %p\n", i, c);

	alloc1.deallocate(i);
	alloc2.deallocate(c);

	return 0;
}
