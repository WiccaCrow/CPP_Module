#include "Ice.hpp"

/******************************************************************************/
/* Constructors */

//      init
Ice::Ice(void) :
                    AMateria("ice")
{
    std::cout << "Ice:      constructor called" << std::endl;
}

//      copy

Ice::Ice(const Ice &obj) :
                    AMateria("ice")
{
    std::cout << "Ice: copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

Ice::~Ice()
{
    std::cout << "Ice:       destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

Ice &   Ice::operator=(const Ice &obj)
{
    std::cout << "Ice:    Assignation operator called " << std::endl;
    if (this != &obj)
        {;}
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

        /* other methods */

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
