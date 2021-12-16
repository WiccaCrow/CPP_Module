#ifndef MAIN_HPP
# define MAIN_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    std::string some_str1;
    std::string some_str2;
};

void        test_color(const std::string text = "test");
uintptr_t   serialize(Data* ptr);
Data*       deserialize(uintptr_t raw);

#endif