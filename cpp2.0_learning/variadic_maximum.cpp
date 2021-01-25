/*************************************************************************
    > File Name: variadic_maximum.cpp
    > Author:
    > Mail:
    > Created Time: 2021年01月23日 星期六 19时26分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

namespace nscpp
{
    int maximum(int n)
    {
        return n;
    }
    template <typename... Args>
    int maximum(int n, Args... args)
    {
        return ::max(n, maximum(args...));
    }
} // namespace nscpp

int main()
{
    cout << nscpp::maximum(57, 48, 60) << endl;
    return 0;
}