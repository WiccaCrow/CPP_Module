#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void    test_1_ShrubberyCreationForm_all_good(Bureaucrat &Vova, ShrubberyCreationForm &shr_1, ShrubberyCreationForm &shr_2);
void    test_1_ShrubberyCreationForm_not_signed(Bureaucrat &Vova, ShrubberyCreationForm &shr_2);
void    test_1_ShrubberyCreationForm_exception_low_signed(Bureaucrat &Vova, ShrubberyCreationForm &shr_2);
void    test_1_ShrubberyCreationForm_exception_low_execute(Bureaucrat &Vova, ShrubberyCreationForm &shr_2);

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

void    test_1_ShrubberyCreationForm()
{
    test_h1lvl_cout_green_color("test_1_ShrubberyCreationForm()");
    test_h3lvl_cout_blue_color("Bureaucrat Vova(\"Vova\", 100);");
    Bureaucrat Vova("Vova", 100);
    std::cout << Vova << std::endl;

    test_h3lvl_cout_blue_color("ShrubberyCreationForm shr_1;");
    ShrubberyCreationForm shr_1;
    std::cout << shr_1 << std::endl;

    test_h3lvl_cout_blue_color("ShrubberyCreationForm shr_2(\"new_year\");");
    ShrubberyCreationForm shr_2("new_year");
    std::cout << shr_2 << std::endl;

    test_1_ShrubberyCreationForm_not_signed(Vova, shr_2);
    test_1_ShrubberyCreationForm_exception_low_signed(Vova, shr_2);
    test_1_ShrubberyCreationForm_exception_low_execute(Vova, shr_2);
    test_1_ShrubberyCreationForm_all_good(Vova, shr_1, shr_2);
}

void    test_1_ShrubberyCreationForm_all_good(Bureaucrat &Vova, ShrubberyCreationForm &shr_1, ShrubberyCreationForm &shr_2)
{
    test_h2lvl_cout_green_color("test all good");
    try
    {
        test_h3lvl_cout_blue_color("Vova.increaseGrade(10);");
        Vova.increaseGrade(10);
        test_h3lvl_cout_blue_color("Vova.signForm(shr_1);");
        Vova.signForm(shr_1);

        test_h3lvl_cout_blue_color("Vova.anexecuteForm(shr_1);");
        Vova.anexecuteForm(shr_1);

        test_h2lvl_cout_green_color("test_2 without exception");

        test_h3lvl_cout_blue_color("Vova.anexecuteForm(shr_2);");
        Vova.anexecuteForm(shr_2);  
    }    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test_1_ShrubberyCreationForm_not_signed(Bureaucrat &Vova, ShrubberyCreationForm &shr_2)
{
    test_h2lvl_cout_green_color("test with exception - execute not signed form");
    test_h3lvl_cout_blue_color("Vova.anexecuteForm(shr_2);");
    Vova.anexecuteForm(shr_2);    
}

void    test_1_ShrubberyCreationForm_exception_low_signed(Bureaucrat &Vova, ShrubberyCreationForm &shr_2)
{
    test_h2lvl_cout_green_color("test with exception - cannot signed form");
    test_h3lvl_cout_blue_color("Vova.decreaseGrade(50);");
    Vova.decreaseGrade(50);
    test_h3lvl_cout_blue_color("Vova.signForm(shr_2);");
    Vova.signForm(shr_2);
}

void    test_1_ShrubberyCreationForm_exception_low_execute(Bureaucrat &Vova, ShrubberyCreationForm &shr_2)
{
    test_h2lvl_cout_green_color("test with exception - cannot exec form");
    test_h3lvl_cout_blue_color("Vova.increaseGrade(10);");
    Vova.increaseGrade(10);
    test_h3lvl_cout_blue_color("Vova.signForm(shr_2);");
    Vova.signForm(shr_2);
    test_h3lvl_cout_blue_color("Vova.anexecuteForm(shr_2);");
    Vova.anexecuteForm(shr_2);
}

int main(void)
{
    test_1_ShrubberyCreationForm();

    return (0);
}