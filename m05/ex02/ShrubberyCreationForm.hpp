#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    private:
        std::string _target;
    public:
        /* Constructs and destructs*/
        ShrubberyCreationForm(std::string target = "");
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();

        /* operators */
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

        /* Set atributs */
        /* Get and show atributs */
        std::string get_target() const;
        /* other methods */

};

#endif