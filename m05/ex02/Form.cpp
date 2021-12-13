#include "Form.hpp"

/******************************************************************************/
/* Constructors */

//      init

Form::Form(const std::string name, const int grade_sign, const int grade_exec) :

        _name (name),   
        _grade_sign (grade_sign),
        _grade_execute (grade_exec),
        _indicate_signed (false)
{
        std::cout << "__Form " << _name << "__:      constructor called\n";
        check_exception(1, 150);
}

//      copy

Form::Form(const Form &obj) :
        _name (get_name()),
        _grade_sign (get_grade_sign()),
        _grade_execute (get_grade_exec())
{
        std::cout << "__Form " << _name << "__: copy constructor called\n";
        operator=(obj);
}

/******************************************************************************/
/* Destructors */

Form::~Form()
{
        std::cout << "__Form " << _name << "__:      destructor called\n";
}

/******************************************************************************/
/* Operators */

//      =

Form &Form::operator=(const Form &obj)
{
        std::cout << "__Form " << _name << "__:      Assignation operator called\n";
        if (this != &obj)
        {
                _indicate_signed = obj.get_indicate_signed();
        }
        return (*this);
}

/******************************************************************************/
/* Private functions */

void    Form::check_exception(int hight, int low)
{
        if (_grade_sign < hight || _grade_sign < hight)
        {
                throw GradeTooHighException();
        }
        else if (_grade_sign > low || _grade_execute  > low )
        {
                throw GradeTooLowException();
        }
}

/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

std::string Form::get_name(void) const
{
        return (_name);
}

int         Form::get_grade_sign(void) const
{
        return (_grade_sign);
}

int         Form::get_grade_exec(void) const
{
        return (_grade_execute);
}

bool        Form::get_indicate_signed(void) const
{
        return (_indicate_signed);
}

void        Form::show_all(void) const
{
        std::cout << get_name()
                  << ", Form grade to sign "
                  << get_grade_sign()
                  << ", grade to execute "
                  << get_grade_exec()
                  << ", is sign: "
                  << get_indicate_signed()
                  << std::endl;
}

        /* other methods */

void    Form::beSigned(const Bureaucrat &bur)
{
        if (!_indicate_signed && bur.getGrade() <= _grade_sign)
        {
                _indicate_signed = true;
        }
        else if (!_indicate_signed)
                throw GradeTooLowException();
}

/******************************************************************************/
/******************************************************************************/
        /* EXCEPTION */ /*GradeTooHighException*/


/******************************************************************************/
/* Constructors */

//      init

Form::GradeTooHighException::
            GradeTooHighException(const std::string message) :
                                          _message (message)
{ }

Form::GradeTooHighException::
            ~GradeTooHighException()  throw()
{ }

const char * Form::GradeTooHighException::
            what() const throw()
{
        return _message.c_str();
}

/******************************************************************************/
/******************************************************************************/
        /* EXCEPTION */ /*GradeTooLowException*/


/******************************************************************************/
/* Constructors */

//      init

Form::GradeTooLowException::
            GradeTooLowException(const std::string message) :
                                         _message (message)
{ }

Form::GradeTooLowException::
            ~GradeTooLowException()  throw()
{ }

const char * Form::GradeTooLowException::
            what() const throw()
{
        return _message.c_str();
}

/******************************************************************************/
/******************************************************************************/

// overload of the<<operator to ostream

std::ostream &       operator<<(std::ostream &ost_obj, Form &bur_obj)
{
        bur_obj.show_all();
        return (ost_obj);
}
