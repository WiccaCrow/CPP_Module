#include "RobotomyRequestForm.hpp"

/******************************************************************************/
/* Constructors */

//      init

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
        Form("RobotomyRequestForm", 72, 45),
        _target (target),
        _i_robotomize (0)
{
    std::cout << "__" << get_name() << "__:      constructor called\n";
}

//      copy

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) :
        Form("RobotomyRequestForm", 72, 45)
{
    std::cout << "__" << get_name() << "__:      copy constructor called\n";
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "__" << get_name() << "__:      destructor called\n";
}

/******************************************************************************/
/* Operators */

//      =

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    std::cout << "__" << get_name() << "__:      Assignation operator called\n";
    if (this != &obj)
    {
        Form::operator=(obj);
        _target = obj.get_target();
        _i_robotomize = obj._i_robotomize;
    }
    return (*this);
}

/******************************************************************************/
/* Private functions */

/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

std::string    RobotomyRequestForm::get_target() const
{
    return (_target);
}

        /* other methods */

void    up__i_robotomize(int *_i_robotomize)
{
    (*_i_robotomize)++;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{    
    Form::execute(executor);
    std::cout << "RobotomyRequestForm: some drilling noises " << std::endl;

    up__i_robotomize((int *)&_i_robotomize);
    if (_i_robotomize % 2)
        std::cout << _target << " has been robotomized." << std::endl;
    else
        std::cout << "  it’s a failure " << std::endl;
}