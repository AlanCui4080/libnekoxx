#include <utility>
#include "test.hpp"
using namespace std;

int main()
{
	struct not_default {
		not_default() = delete;
		auto foo() const -> unsigned long long
		{
			return 1;
		}
	};

	decltype(std::declval<not_default>().foo()) a =
		(unsigned long long)0 - 1;

	return a + 1;
}
