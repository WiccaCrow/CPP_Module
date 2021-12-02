#ifndef CLASSSTRING_MY_HPP
# define CLASSSTRING_MY_HPP

#include <iostream>

class String_my : public std::string
{
    public:
        String_my(const char *);
        String_my(const std::string);
        String_my(void);
        ~String_my();
};

#endif
