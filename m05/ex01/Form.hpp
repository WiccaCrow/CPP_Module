#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        const int         _grade_sign;
        const int         _grade_execute;
        bool              _indicate_signed;

        void    check_exception(int hight, int low);
    public:
        /* Constructs and destructs*/
        Form(const std::string name = "no name", const int grade_sign = 150, const int grade_exec = 150);
        Form(const Form &obj);
        ~Form();

        /* operators */
        Form &operator=(const Form &obj);
        
        /* Set atributs */
        /* Get and show atributs */
        std::string get_name(void) const;
        int         get_grade_sign(void) const;
        int         get_grade_exec(void) const;
        bool        get_indicate_signed(void) const;
        void        show_all(void) const;

        /* other methods */
        void    beSigned(const Bureaucrat &bur);

        /* exception */
        class GradeTooHighException : public std::exception
        {
            private:
                const std::string _message;
            public:
                GradeTooHighException(const std::string message = "    < Exception > : this grade is too hight. ");
                virtual ~GradeTooHighException() throw();
                virtual const char * what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            private:
                const std::string _message;
            public:
                GradeTooLowException(const std::string message = "    < Exception > : this grade is too low. ");
                virtual ~GradeTooLowException() throw();
                virtual const char * what() const throw();
        };
};

std::ostream &       operator<<(std::ostream &ost_obj, Form &f_obj);

#endif