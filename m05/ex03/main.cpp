#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

//______________________________________________________________________//
// Color output
//______________________________________________________________________//

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

//______________________________________________________________________//
//______________________________________________________________________//

int main(void)
{
    test_h1lvl_cout_green_color("Test Intern");

    Intern  someRandomIntern;
    Form*   rrf;

    test_h2lvl_cout_green_color("RobotomyRequestForm");
    test_h3lvl_cout_blue_color("rrf = someRandomIntern.makeForm(\"robotomy request\", \"Bender\");");
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    test_h3lvl_cout_blue_color("delete rrf;");
    delete rrf;

    test_h2lvl_cout_green_color("ShrubberyCreationForm");
    test_h3lvl_cout_blue_color("rrf = someRandomIntern.makeForm(\"shrubbery creation\", \"Home\");");
    rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
    test_h3lvl_cout_blue_color("delete rrf;");
    delete rrf;

    test_h2lvl_cout_green_color("PresidentialPardonForm");
    test_h3lvl_cout_blue_color("rrf = someRandomIntern.makeForm(\"robotomy request\", \"Mark\");");
    rrf = someRandomIntern.makeForm("presidential pardon", "Mark");
    test_h3lvl_cout_blue_color("delete rrf;");
    delete rrf;

    test_h2lvl_cout_green_color("unknown form");
    test_h3lvl_cout_blue_color("rrf = someRandomIntern.makeForm(\"unknown form\", \"sdfghj\");");
    rrf = someRandomIntern.makeForm("unknown form", "sdfghj");
    test_h3lvl_cout_blue_color("delete rrf;");
    delete rrf;

    return (0);
}