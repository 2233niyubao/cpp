/*************************************************************************
    > File Name: variadic_printf.cpp
    > Author: 
    > Mail: 
    > Created Time: 2021年01月23日 星期六 16时42分32秒
 ************************************************************************/

#include<iostream>
using namespace std;

namespace nscpp
{
	void printf(const char *s)
	{
		while (*s)
		{
			if (*s == '%' && *(++s) != '%')
			{
				throw runtime_error("invalid format string::miss arguments");
			}
			cout << *s++;
		}
	}

	template <typename T, typename... Args>
	void printf(const char *s, T value, Args... args)
	{
		while (*s)
		{
			if (*s == '%' && *(++s) != '%')
			{
				cout << value;
				printf(++s, args...);
				return;
			}
			cout << *s++;
		}
		throw logic_error("extra arguments provided to printf");
	}
} // namespace nscpp

int main()
{
	int *pi = new int;
	nscpp::printf("%d %s %p %f\n",
				  15,
				  "This is Ace",
				  pi,
				  3.141592653);
	delete pi;
	return 0;
}
