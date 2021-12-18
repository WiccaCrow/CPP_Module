#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Form.hpp"

# define ERROR_FILE_REPLACE_OPEN "Error: the file can't be opened or created."

class ShrubberyCreationForm : public Form
{
    private:
        std::string _target;
    public:
        /* Constructs and destructs*/
        ShrubberyCreationForm(std::string target = "");
        ShrubberyCreationForm(const ShrubberyCreationForm &obj);
        virtual  ~ShrubberyCreationForm();

        /* operators */
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

        /* Set atributs */
        /* Get and show atributs */
        std::string     get_target() const;

        /* other methods */
        virtual void    execute(Bureaucrat const & executor) const;
};

#endif