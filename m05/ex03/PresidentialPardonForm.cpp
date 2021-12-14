#include "PresidentialPardonForm.hpp"

/******************************************************************************/
/* Constructors */

//      init
PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
        Form("PresidentialPardonForm", 25, 5),
        _target (target)
{
    std::cout << "__" << get_name() << "__:      constructor called\n";
}

//      copy

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) :
        Form("PresidentialPardonForm", 25, 5)
{
    std::cout << "__" << get_name() << "__:      copy constructor called\n";
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "__" << get_name() << "__:      destructor called\n";
}

/******************************************************************************/
/* Operators */

//      =

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    std::cout << "__" << get_name() << "__:      Assignation operator called\n";
    if (this != &obj)
    {
        Form::operator=(obj);
        _target = obj.get_target();
    }
    return (*this);
}

/******************************************************************************/
/* Private functions */

/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */
std::string    PresidentialPardonForm::get_target() const
{
    return (_target);
}

        /* other methods */

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{    
    Form::execute(executor);
    std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
