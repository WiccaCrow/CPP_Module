#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        const std::string _name;
        int         _grade;

        void    changeGrade(const int &change_grade);
        void    check_exception();
    public:
        /* Constructs and destructs*/
        Bureaucrat(const std::string name = "Anonymous", const int grade = 150);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();

        /* operators */
        Bureaucrat &operator=(const Bureaucrat &obj);
        
        /* Set atributs */
        /* Get and show atributs */
        std::string getName(void) const;
        int         getGrade(void) const;
        void        show_all(void) const;

        /* other methods */
        void    increaseGrade(const int &set_up = 1);
        void    decreaseGrade(const int &set_down = 1);

        /* exception */
        class GradeTooHighException : public std::exception
        {
            private:
                const std::string _message;
            public:
                GradeTooHighException(const std::string message = "    < Exception > : this grade is too hight. Grade must be from 150 to 1. Try again.");
                virtual ~GradeTooHighException() throw();
                virtual const char * what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            private:
                const std::string _message;
            public:
                GradeTooLowException(const std::string message = "    < Exception > : this grade is too low. Grade must be from 150 to 1. Try again.");
                virtual ~GradeTooLowException() throw();
                virtual const char * what() const throw();
        };
};

std::ostream &       operator<<(std::ostream &ost_obj, Bureaucrat &bur_obj);

#endif