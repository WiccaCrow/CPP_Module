#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iterator>
#include <algorithm>

template <typename T>
typename T::iterator      easyfind(T &t, int i)
{
    typename T::iterator iter;

    iter = std::find(t.begin(), t.end(), i);
    if (iter == t.end())
    {
        throw 1; // i not found in t
    }
    return (iter);
}

#endif