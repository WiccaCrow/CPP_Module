#include "WrongCat.hpp"

/******************************************************************************/
/* Constructors */

//      init

WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
    std::cout << "WrongCat: constructor called" << std::endl;
}

//      copy

WrongCat::WrongCat(const WrongCat &obj)
{
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

WrongCat::~WrongCat()
{ 
    std::cout << "WrongCat: destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

WrongCat &    WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "WrongCat:    Assignation operator called " << std::endl;
    if (this != &obj)
        type = obj.getType();
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set private members*/
        /* Get and show private members*/
        /* other methods */
void    WrongCat::makeSound(void) const
{

    std::cout << "\033[0;31mWrongCat WrongCat WrongCat: Murrrrr-Mrrr.... \033[0m" << std::endl;
}