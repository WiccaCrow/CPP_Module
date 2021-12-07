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

Ice::Ice(const Ice &obj)
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

std::string const & Ice::getType() const
{
    return (_type);
}

        /* other methods */

AMateria* Ice::clone() const
{
    return (new Ice(_type));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
