#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    private:
        std::string _name;
        int         _grade;
    public:
        /* Constructs and destructs*/
        Bureaucrat(const int &grade = 0);
        Bureaucrat(const std::string &name, const int &grade);
        Bureaucrat(const Bureaucrat &obj);
        ~Bureaucrat();
        /* operators */
        Bureaucrat &operator=(const Bureaucrat &obj);
        /* Set atributs */
        /* Get and show atributs */
        std::string getName(void);
        int         getGrade(void);

        /* other methods */
        void    increaseGrade(int   set_up);
        void    decreaseGrade(int   set_down);

        /* exception */
        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
        };
};

#endif