#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/* Constructors */

//      init
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
        Form("ShrubberyCreationForm", 145, 137),
        _target (target)
{
    std::cout << "__" << get_name() << "__:      constructor called\n";

}

//      copy

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) :
        Form("ShrubberyCreationForm", 145, 137)
{
    std::cout << "__" << get_name() << "__:      copy constructor called\n";
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "__" << get_name() << "__:      destructor called\n";
}

/******************************************************************************/
/* Operators */

//      =

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
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
std::string    ShrubberyCreationForm::get_target() const
{
    return (_target);
}

        /* other methods */

/*
              #
             ***
            *****
           *****~~
            **~~~
           *~~~***
          ~~~******
         ~~*********
        *************
         ***********
        *************
       ***************
      *@***************
     ***@************@**
    *@****************@**
      @****************
     *******************
    *****@***************
   ***********************
  ********@****************
 *****************@*********
*****************************
            |||||
            |||||   _8_8_
            |||||  |  |  |_8_
            |||||  |__|__|___|
*/