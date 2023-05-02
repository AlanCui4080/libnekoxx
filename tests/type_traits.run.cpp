#include <type_traits>
#include "test.hpp"

using namespace std;

int main()
{
	INIT_TEST();

	TEST_TRUE((is_same_v<int, int>));
	TEST_FALSE((is_same_v<int, long>));

	TEST_TRUE((is_same_v<int, remove_cv_t<int>>));
	TEST_TRUE((is_same_v<int, remove_cv_t<const volatile int>>));
	TEST_TRUE((is_same_v<int, remove_cv_t<const int>>));
	TEST_TRUE((is_same_v<int, remove_cv_t<volatile int>>));

	TEST_TRUE((is_same_v<int, remove_const_t<int>>));
	TEST_TRUE((is_same_v<int, remove_const_t<const int>>));

	TEST_TRUE((is_same_v<int, remove_volatile_t<int>>));
	TEST_TRUE((is_same_v<int, remove_volatile_t<volatile int>>));

	TEST_TRUE((is_same_v<const int, add_const_t<const int>>));
	TEST_TRUE((is_same_v<const int, add_const_t<int>>));

	TEST_TRUE((is_same_v<volatile int, add_volatile_t<volatile int>>));
	TEST_TRUE((is_same_v<volatile int, add_volatile_t<int>>));

	TEST_TRUE((is_same_v<const volatile int, add_cv_t<int>>));

	TEST_TRUE((is_void_v<void>));
	TEST_FALSE((is_void_v<int>));

	TEST_TRUE((is_null_pointer_v<nullptr_t>));
	TEST_FALSE((is_null_pointer_v<int>));

	TEST_FALSE((is_integral_v<int *>));
	TEST_TRUE((is_integral_v<bool>));
	TEST_TRUE((is_integral_v<char>));
	TEST_TRUE((is_integral_v<char16_t>));
	TEST_TRUE((is_integral_v<char32_t>));
	TEST_TRUE((is_integral_v<wchar_t>));
	TEST_TRUE((is_integral_v<short>));
	TEST_TRUE((is_integral_v<int>));
	TEST_TRUE((is_integral_v<long>));
	TEST_TRUE((is_integral_v<long long>));

        TEST_FALSE((is_floating_point_v<float*>));
        TEST_TRUE((is_floating_point_v<float>));
        TEST_TRUE((is_floating_point_v<double>));
        TEST_TRUE((is_floating_point_v<long double>));

        TEST_FALSE((is_array_v<int>));
        TEST_TRUE((is_array_v<int[]>));
        TEST_TRUE((is_array_v<int[1]>));

        TEST_FALSE((is_lvalue_reference_v<int>));
        TEST_TRUE((is_lvalue_reference_v<int&>));

        TEST_FALSE((is_rvalue_reference_v<int>));
        TEST_TRUE((is_rvalue_reference_v<int&&>));

        TEST_TRUE((is_same_v<remove_reference<int>::type, int>));
        TEST_TRUE((is_same_v<remove_reference<int&>::type, int>));
        TEST_TRUE((is_same_v<remove_reference<int&&>::type, int>));

        TEST_TRUE((is_same_v<add_lvalue_reference<int>::type, int&>));
        TEST_TRUE((is_same_v<add_rvalue_reference<int>::type, int&&>));

        TEST_TRUE((is_same_v<conditional_t<true,int,void>,int>));
        TEST_TRUE((is_same_v<conditional_t<false,int,void>,void>));

        TEST_TRUE((is_convertible_v<int, float>));
        TEST_TRUE((is_convertible_v<int, int>));
        TEST_FALSE((is_convertible_v<int, void>));
        TEST_FALSE((is_convertible_v<void, int>));
        TEST_FALSE((is_convertible_v<void, int>));

	TEST_FALSE((is_const_v<int>));
	TEST_FALSE((is_const_v<const int*>));
	TEST_FALSE((is_const_v<int const*>));
	TEST_TRUE((is_const_v<const int>));

	TEST_FALSE((is_volatile_v<int>));
	TEST_FALSE((is_volatile_v<volatile int*>));
	TEST_FALSE((is_volatile_v<int volatile*>));
	TEST_TRUE((is_volatile_v<volatile int>));


	END_TEST();
}
