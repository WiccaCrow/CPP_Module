#include "Bureaucrat.hpp"

/******************************************************************************/
/* Constructors */

//      init

Bureaucrat::Bureaucrat(const std::string name, const int &grade) : 
                                   _name (name),   _grade (grade)
{
        if (_grade < 1)
                throw GradeTooHighException();
}

//      copy

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
        operator=(obj);
}

/******************************************************************************/
/* Destructors */

Bureaucrat::~Bureaucrat()
{}

/******************************************************************************/
/* Operators */

//      =

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
        if (this != &obj)
        {
                _grade = obj.getGrade();
        }
        return (*this);
}

/******************************************************************************/
/* Private functions */

void    Bureaucrat::changeGrade(const int &change_grade)
{
        _grade += change_grade;
        std::cout << "The grade has been changed to "
                << (change_grade > 0 ? change_grade : -change_grade)
                << " and the score is now "
                << getGrade()
                << ". " 
                << std::endl;

}

/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

std::string Bureaucrat::getName(void) const
{
        return (_name);
}

int         Bureaucrat::getGrade(void) const
{
        return (_grade);
}

void        Bureaucrat::show_all(void) const
{
        std::cout << getName()
                  << ", bureaucrat grade "
                  << getGrade()
                  << std::endl;
}

        /* other methods */

void    Bureaucrat::decreaseGrade(const int &set_up)
{
        std::cout << "decreaseGrade: ";
        changeGrade(set_up);
}

void    Bureaucrat::increaseGrade(const int &set_down)
{
        std::cout << "increaseGrade: ";
        int set_down_new = -set_down;
        changeGrade(set_down_new);
}

/******************************************************************************/
/******************************************************************************/

// overload of the<<operator to ostream

std::ostream &       operator<<(std::ostream &ost_obj, Bureaucrat &bur_obj)
{
        bur_obj.show_all();
        return (ost_obj);
}

/******************************************************************************/
/******************************************************************************/
        /* EXCEPTION */


/******************************************************************************/
/* Constructors */

//      init
Bureaucrat::GradeTooHighException::
            GradeTooHighException(const std::string message) :
                                          _message (message)
{ }

Bureaucrat::GradeTooHighException::
            ~GradeTooHighException()  throw()
{ }

const char * Bureaucrat::GradeTooHighException::
            what() const throw()
{
        return _message.c_str();
}
