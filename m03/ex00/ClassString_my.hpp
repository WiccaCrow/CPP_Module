#ifndef CLASSSTRING_MY_HPP
# define CLASSSTRING_MY_HPP

#include <iostream>

class String_my
{
    private:
        std::string some_string;
    public:
    String_my(char *);
    String_my(void);
    ~String_my();
};

String_my::String_my(char *str)
{
    if (str)
        some_string = str;
    else
    {
        std::cout << "\n\n_________________________________________________________\n"
                  << "| my_string:: Bad bad bad                               |\n"
                  << "| very bad                                              |\n"
                  << "| you supplied a null pointer instead of a string.      |\n" 
                  << "| Don't do that.                                        |\n" 
                  << "| Ok. Now I will give you the string \"It_was_NullPtr\".  |\n"
                  << "| Accept this or correct your code.                     |\n"
                  << "|_______________________________________________________|\n"
                  << std::endl;
        some_string = "It_was_NullPtr";
    }
}

String_my::String_my(void)
{ }

String_my::~String_my()
{ }


#endif
