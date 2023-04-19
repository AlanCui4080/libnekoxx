#include<cstdio>
#include<string>

void pbool(bool v)
{
	printf("%s\n", v ? "true" : "false");
}

int main()
{
	pbool(std::char_traits<char>::eq('a', 'b'));
	pbool(std::char_traits<char>::eq('f', 'f'));
	pbool(std::char_traits<char>::lt('a', 'b'));

	const char *src = "This is a sentence";
	printf("%d %p\n", static_cast<int>((src -
				std::char_traits<char>::find(src, strlen(src),
							     'i'))),
			  (void*)std::char_traits<char>::
			  	 find(src, strlen(src), 'z'));

	char *s = new char[strlen(src) + 1];
	printf("%d\n", std::char_traits<char>::
		       compare(src, std::char_traits<char>::copy(s, src,
		       						 strlen(src)),
			       strlen(src)));

	printf("%d\n", std::char_traits<char>::eof());

	delete [] s;

	return 0;
}
