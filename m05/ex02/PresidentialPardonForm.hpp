#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string _target;
    public:
        /* Constructs and destructs*/
        PresidentialPardonForm(std::string target = "Anonymus");
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        virtual ~PresidentialPardonForm();
        
        /* operators */
        PresidentialPardonForm &   operator=(const PresidentialPardonForm &obj);

        /* Set atributs */
        /* Get and show atributs */
        std::string     get_target() const;

        /* other methods */
        virtual void    execute(Bureaucrat const & executor) const;
};

#endif
