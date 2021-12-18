#include "ClassString_my.hpp"

String_my::String_my(const char *str) :
        std::string(str ? str : "It_was_NullPtr")
{
    if (!str)
    {
        std::cout << "\n\033[31m_________________________________________________________\n"
                  << "| my_string:: Bad bad bad                               |\n"
                  << "| very bad                                              |\n"
                  << "| you supplied a null pointer instead of a string.      |\n" 
                  << "| Don't do that.                                        |\n" 
                  << "| Ok. Now I will give you the string \"It_was_NullPtr\".  |\n"
                  << "| Accept this or correct your code.                     |\n"
                  << "|_______________________________________________________|\033[0m\n"
                  << std::endl;
    }
}

String_my::String_my(const std::string str) :
        std::string(str)
{ }

String_my::String_my(void)
{ }

String_my::~String_my()
{ }
