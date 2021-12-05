#include "WrongAnimal.hpp"

/******************************************************************************/
/* Constructors */

//      init

WrongAnimal::WrongAnimal(std::string type_in) : type (type_in)
{
    std::cout << "WrongAnimal: constructor called" << std::endl;
}

//      copy

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

WrongAnimal::~WrongAnimal()
{ 
    std::cout << "WrongAnimal: destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

WrongAnimal &    WrongAnimal::operator=(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal:    Assignation operator called " << std::endl;
    if (this != &obj)
        type = obj.getType();
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set private members*/

std::string WrongAnimal::getType(void) const
{
    return (type);
}
        /* Get and show private members*/

        /* other methods */
void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal: - " << std::endl;
}
