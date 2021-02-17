/*************************************************************************
    > File Name: variadic_max.cpp
    > Author: 
    > Mail: 
    > Created Time: 2021年01月23日 星期六 17时49分21秒
 ************************************************************************/

#include<iostream>
#include<initializer_list>
using namespace std;

namespace nscpp
{
    struct _Iter_less_iter
    {
        template <typename _Iterator1, typename _Iterator2>
        bool operator()(_Iterator1 __it1, _Iterator2 __it2) const
        {
            return *__it1 < *__it2;
        }
    };

    inline _Iter_less_iter __iter_less_iter()
    {
        return _Iter_less_iter();
    }

    template <typename _ForwardIterator, typename _Compare>
    _ForwardIterator __max_element(_ForwardIterator __first,
                                   _ForwardIterator __last,
                                   _Compare __comp)
    {
        if (__first == __last)
            return __first;
        _ForwardIterator __result = __first;
        while (++__first != __last)
        {
            if (__comp(__result, __first))
                __result = __first;
        }
        return __result;
    }

    template <typename _ForwardIterator>
    inline _ForwardIterator 
    max_element(_ForwardIterator __first,
                _ForwardIterator __last)
    {
        return __max_element(__first, __last, __iter_less_iter());
    }

    template <typename _Tp>
    inline _Tp max(initializer_list<_Tp> __l)
    {
        return *max_element(__l.begin(), __l.end());
    }
}

int main()
{
    cout << nscpp::max({57, 48, 60}) << endl;
    return 0;
}
