#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    private:
        std::string _target;
        int         _i_robotomize;
    public:
        /* Constructs and destructs*/
        RobotomyRequestForm(std::string target = "Anonymus");
        RobotomyRequestForm(const RobotomyRequestForm &obj);
        virtual ~RobotomyRequestForm();
        
        /* operators */
        RobotomyRequestForm &   operator=(const RobotomyRequestForm &obj);

        /* Set atributs */
        /* Get and show atributs */
        std::string     get_target() const;

        /* other methods */
        virtual void    execute(Bureaucrat const & executor) const;
};

#endif
