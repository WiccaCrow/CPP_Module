#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <vector>
#include <map>

void    test_color(const std::string text);
void    test_array_class(void);
void    test_vector_class(void);

int main ()
{
    test_array_class();
    test_vector_class();
    
    return (0);
}

/*********************/
/*        test_color */
/*********************/
/* Description:
 *      Color output.
*/

void    test_color(const std::string text)
{
    std::cout << std::endl << "\033[36m" << text << "\033[0m";
}

void    test_array_class(void)
{
    std::cout << "\n\x1b[30;42m" << "test_array_class" << "\x1b[0m" << std::endl;
    test_color("std::array<int, 4> Arr_in = { 1, 2, 3, 4 };\n");
    test_color("1. Finding the number 3\n");


    std::array<int, 4> Arr_in = { 1, 2, 3, 4 };
    try
    {
        if (&Arr_in[2] == easyfind(Arr_in, 3))
            std::cout << "Function easyfind works: " << Arr_in[2] << std::endl;

        test_color("1. Finding the number 5\n");
        if (&Arr_in[2] == easyfind(Arr_in, 5))
            std::cout << "Function easyfind works: " << Arr_in[2] << std::endl;
        else
            std::cout << "We never see it." << std::endl;
    }
    catch(int &exc)
    {
        std::cerr << "<exception>: error code " << exc << ". This number is not in the array." << std::endl;
    }
}

void    test_vector_class(void)
{
    std::cout << "\n\x1b[30;42m" << "test_vector_class" << "\x1b[0m" << std::endl;
    test_color("std::vector<int> Arr_in(5, 88);\n");
    test_color("1. Finding the number 88\n");

    std::vector<int> Arr_in(5, 88);
    try
    {
        std::vector<int>::iterator iter = easyfind(Arr_in, 88);
        std::cout << "Function easyfind works: " << *iter << std::endl;

        test_color("1. Finding the number 5\n");
        iter = easyfind(Arr_in, 5);
        std::cout << "Function easyfind works: " << *iter << std::endl;
    }
    catch(int &exc)
    {
        std::cerr << "<exception>: error code " << exc << ". This number is not in the array." << std::endl;
    }
}

