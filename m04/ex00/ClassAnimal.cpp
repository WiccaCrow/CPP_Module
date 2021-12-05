#include "ClassAnimal.hpp"

/******************************************************************************/
/* Constructors */

//      init

Animal::Animal(std::string type_in) : type (type_in)
{
    std::cout << "Animal: constructor called" << std::endl;
}

//      copy

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

Animal::~Animal()
{ 
    std::cout << "Animal: destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

Animal &    Animal::operator=(const Animal &obj)
{
    std::cout << "Animal:    Assignation operator called " << std::endl;
    if (this != &obj)
        type = obj.getType();
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set private members*/

std::string Animal::getType(void) const
{
    return (type);
}
        /* Get and show private members*/

        /* other methods */
void    Animal::makeSound(void) const
{
    std::cout << "Animal: - " << std::endl;
}
