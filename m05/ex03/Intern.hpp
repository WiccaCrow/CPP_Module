#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        Form * (Intern::*func_ptr[3])(std::string &target);
        std::string _form_name[3];
    public:
        /* Constructs and destructs*/
        Intern(void);
        Intern(const Intern &obj);
        ~Intern();
        
        /* operators */
        Intern &    operator=(const Intern &obj);

        /* Set atributs */
        /* Get and show atributs */
        /* other methods */
        Form *  makeForm(std::string form_name, std::string target);
        Form *  newRobotomyRequestForm(std::string &target);
        Form *  newShrubberyCreationForm(std::string &target);
        Form *  newPresidentialPardonForm(std::string &target);
};

#endif
