#include "Intern.hpp"

/******************************************************************************/
/* Constructors */

//      init
Intern::Intern(void)
{
    _form_name[0] = "robotomy request";
    _form_name[1] = "shrubbery creation"; 
    _form_name[2] = "presidential pardon"; 

    func_ptr[0] = &Intern::newRobotomyRequestForm;
    func_ptr[1] = &Intern::newShrubberyCreationForm;
    func_ptr[2] = &Intern::newPresidentialPardonForm;
}

//      copy

Intern::Intern(const Intern &obj)
{ 
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

Intern::~Intern()
{ }

/******************************************************************************/
/* Operators */

//      =

Intern &    Intern::operator=(const Intern &obj)
{
    if (this != &obj)
    {}

    return (*this);
}

/******************************************************************************/
/* Private functions */

/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

        /* other methods */

Form *  Intern::makeForm(std::string form_name, std::string target)
{
    int i;

    for (i = 0; i < 3; ++i)
    {
        if (form_name == _form_name[i])
            return (this->*(func_ptr[i]))(target);
    }
    std::cerr << "Error: requested form is not known." << std::endl;
    return (0);
}

Form *  Intern::newRobotomyRequestForm(std::string &target)
{
    return (new RobotomyRequestForm(target));
}

Form *  Intern::newShrubberyCreationForm(std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

Form *  Intern::newPresidentialPardonForm(std::string &target)
{
    return (new PresidentialPardonForm(target));
}