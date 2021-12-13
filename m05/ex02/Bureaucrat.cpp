#include "Bureaucrat.hpp"

/******************************************************************************/
/* Constructors */

//      init

Bureaucrat::Bureaucrat(const std::string name, const int grade) : 
                                   _name (name), _grade (grade)
{
        std::cout << "__Bureaucrat " << _name << "__:      constructor called\n";
        check_exception();
}

//      copy

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
        std::cout << "__Bureaucrat " << _name << "__: copy constructor called\n";
        operator=(obj);
}

/******************************************************************************/
/* Destructors */

Bureaucrat::~Bureaucrat()
{
        std::cout << "__Bureaucrat " << _name << "__:      destructor called\n";
}

/******************************************************************************/
/* Operators */

//      =

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
        std::cout << "__Bureaucrat " << _name << "__:      Assignation operator called\n";
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
        check_exception();
        std::cout << "The grade has been changed to "
                  << (change_grade > 0 ? change_grade : -change_grade)
                  << " and the score is now "
                  << getGrade()
                  << ". " 
                  << std::endl;
}

void    Bureaucrat::check_exception()
{
        if (_grade < 1)
        {
                throw GradeTooHighException();
        }
        else if (_grade > 150)
        {
                throw GradeTooLowException();
        }
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

void    Bureaucrat::signForm(Form &f_obj)
{
        try
        {
                if (!f_obj.get_indicate_signed())
                {
                        f_obj.beSigned(*this);
                        std::cout << getName() << " signs " 
                        << f_obj.get_name() << std::endl;
                }
        } catch (const std::exception& e)
        {
                std::cout << getName() << " cannot sign " 
                        << f_obj.get_name() 
                        << " because " << e.what()
                        << std::endl;
        }
}

void    Bureaucrat::anexecuteForm(Form const & form)
{
        try
        {
                form.execute(*this);
                std::cout << getName() << " executes " << form.get_name() <<std::endl;
        }       catch(const std::exception& e)
        {
                std::cerr << e.what() << '\n';
        }
}


/******************************************************************************/
/******************************************************************************/
        /* EXCEPTION */ /*GradeTooHighException*/


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

/******************************************************************************/
/******************************************************************************/
        /* EXCEPTION */ /*GradeTooLowException*/


/******************************************************************************/
/* Constructors */

//      init

Bureaucrat::GradeTooLowException::
            GradeTooLowException(const std::string message) :
                                         _message (message)
{ }

Bureaucrat::GradeTooLowException::
            ~GradeTooLowException()  throw()
{ }

const char * Bureaucrat::GradeTooLowException::
            what() const throw()
{
        return _message.c_str();
}

/******************************************************************************/
/******************************************************************************/

// overload of the<<operator to ostream

std::ostream &       operator<<(std::ostream &ost_obj, Bureaucrat &bur_obj)
{
        bur_obj.show_all();
        return (ost_obj);
}
