#include <iostream>
#include "Bureaucrat.hpp"

void    test_h1lvl_cout_green_color(const std::string text = "test")
{
    std::cout << "\n\x1b[30;42m" << text << "\x1b[0m" << std::endl;
}

void    test_h2lvl_cout_green_color(const std::string text = "test")
{
    std::cout << "\033[92m" << "  _____________________________________" << std::endl;
    std::cout << "  ||  " << text << std::endl;
    std::cout << "  || \n  \\/ " << "\033[0m" << std::endl;
}

void    test_h3lvl_cout_blue_color(const std::string text = "test")
{
    std::cout << std::endl << "\033[36m" << text << "\n\033[0m";
}

void    test_1_construct()
{
    test_h1lvl_cout_green_color("test_1_construct");
    test_h2lvl_cout_green_color("\nBureaucrat Anon;\nBureaucrat Anna(\"Anna\", 0);\nBureaucrat Anna2(\"Anna_2\", 0);");
    try
    {
        Bureaucrat Anon;
        std::cout << Anon << std::endl;

        Anon.increaseGrade(5);
        std::cout << Anon << std::endl;

        std::cout << "EXCEPTION" << std::endl;

        Bureaucrat Anna("Anna", 0);
        std::cout << Anna << std::endl;

        Bureaucrat Anna2("Anna_2", 0);
    }    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test_2_increase(void)
{
    test_h1lvl_cout_green_color("test_2_increase");
    test_h2lvl_cout_green_color("\n\nBureaucrat Anna(\"Anna\", 10);");
    try
    {
        Bureaucrat Anna("Anna", 10);
        std::cout << Anna << std::endl;

        test_h3lvl_cout_blue_color("Anna.increaseGrade(4);");
        Anna.increaseGrade(4);
        std::cout << Anna << std::endl;

        test_h3lvl_cout_blue_color("Anna.increaseGrade(4);");
        Anna.increaseGrade(4);
        std::cout << Anna << std::endl;

        test_h3lvl_cout_blue_color("Anna.increaseGrade(4);");
        Anna.increaseGrade(4);
        std::cout << Anna << std::endl;

    }    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test_3_decrease(void)
{
    test_h1lvl_cout_green_color("test_3_decrease");
    test_h2lvl_cout_green_color("\n\nBureaucrat Anna(\"Anna\", 100);");
    try
    {
        Bureaucrat Anna("Anna", 100);
        std::cout << Anna << std::endl;

        test_h3lvl_cout_blue_color("Anna.decreaseGrade(24);");
        Anna.decreaseGrade(24);
        std::cout << Anna << std::endl;

        test_h3lvl_cout_blue_color("Anna.decreaseGrade(24);");
        Anna.decreaseGrade(24);
        std::cout << Anna << std::endl;

        test_h3lvl_cout_blue_color("Anna.decreaseGrade(24);");
        Anna.decreaseGrade(24);
        std::cout << Anna << std::endl;

    }    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(void)
{
    test_1_construct();
    test_2_increase();
    test_3_decrease();

    return (0);
}