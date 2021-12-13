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
    test_h2lvl_cout_green_color("\nForm Blank_1;\nForm Blank_2(\"Blank_2\", 100, 105);\nForm Blank_3(\"Blank_3\", 0, 10);");
    try
    {
        Form Blank_1;
        std::cout << Blank_1 << std::endl;

        Form Blank_2("Blank_2", 100, 105);
        std::cout << Blank_2 << std::endl;

        Form Blank_3("Blank_3", 0, 10);
        std::cout << Blank_3 << std::endl;

    }    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test_2_beSigned(void)
{
    test_h1lvl_cout_green_color("test_2_beSigned");
    test_h2lvl_cout_green_color("\nBureaucrat Anna(\"Anna\", 10);\nForm Blank_2(\"Blank_2\", 100, 105);\nAnna.signForm(Blank_2);");
    try
    {
        Bureaucrat Anna("Anna", 10);
        std::cout << Anna << std::endl;

        Form Blank_2("Blank_2", 100, 105);
        std::cout << Blank_2 << std::endl;

        Anna.signForm(Blank_2);
        std::cout << Blank_2 << std::endl;

        test_h2lvl_cout_green_color("\nAnna.decreaseGrade(100);\nForm Blank_3(\"Blank_3\", 100, 105);\nAnna.signForm(Blank_3);");

        Anna.decreaseGrade(100);
        std::cout << Anna << std::endl;

        Form Blank_3("Blank_3", 100, 105);
        std::cout << Blank_3 << std::endl;

        Anna.signForm(Blank_3);
        std::cout << Blank_3 << std::endl;

    }    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(void)
{
    test_1_construct();
    test_2_beSigned();

    return (0);
}