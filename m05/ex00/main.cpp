#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat Anon;
    std::cout << Anon << std::endl;

    Anon.increaseGrade(5);
    std::cout << Anon << std::endl;

    Bureaucrat Anna("Anna", 12);
    std::cout << Anna << std::endl;

    Anna.decreaseGrade(2);
    std::cout << Anna << std::endl;
    Anna.decreaseGrade();
    std::cout << Anna << std::endl;


    std::cout << "EXCEPTION" << std::endl;


    try
    {
        Bureaucrat Anna("Anna", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // std::cout << Anna << std::endl;
    return (0);
}