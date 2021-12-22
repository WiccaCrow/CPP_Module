#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void print_int_to_data(T const &elem)
{
    static int i = 0;
    if (i == 2 || i == 4)
        std::cout << '.';
    std::cout << elem;
    ++i;
}

template <typename T>
void    print_element(T const &elem)
{
    std::cout << elem;
}

template <typename T>
void    iter(T *array, int length, void (*print_element)(T const &))
{
    for (int i = 0; i < length; ++i)
    {
        print_element(array[i]);
    }
}

#endif