#ifndef CLASSSTRING_MY_HPP
# define CLASSSTRING_MY_HPP

#include <iostream>

/******************************
 *    class String_my         *
 * ****************************
 * Description:
 *        The object is derived from std::string.
 *        Supplemented with protection against passing 
 *        a null pointer NULLptr into it.
*/

class String_my : public std::string
{
    public:
        String_my(const char *);
        String_my(const std::string);
        String_my(void);
        ~String_my();
};

#endif
