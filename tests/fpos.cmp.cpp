#include<cstdio>
#include<cwchar>
#include<ios>

int main()
{
	std::fpos<std::mbstate_t> p1(1), p2;
	printf("%d %d\n", p1 == p2, p1 != p2);
	printf("%d %d\n", p1 - (std::streamoff)1 == p2,
	       p2 + (std::streamoff)1 == p1);
	printf("%d\n", 1 + p2 == p1);
	printf("%lld %lld\n", (std::streamoff)p1, (std::streamoff)p2);
	p1 += 5;
	p2 += 5;
	printf("%lld %lld\n", (std::streamoff)p1, (std::streamoff)p2);
}
