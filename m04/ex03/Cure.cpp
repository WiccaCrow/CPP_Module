#include "Cure.hpp"

/******************************************************************************/
/* Constructors */

//      init
Cure::Cure(void) :
                    AMateria("cure")
{
    std::cout << "Cure:      constructor called" << std::endl;
}

//      copy

Cure::Cure(const Cure &obj);
{
    std::cout << "Cure: copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

Cure:~Cure()
{
    std::cout << "Cure:       destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

Cure &   Cure::operator=(const Cure &obj)
{
    std::cout << "Cure:    Assignation operator called " << std::endl;
    // if (this != &obj)
    // {;}
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

std::string const & Cure::getType() const
{
    return (_type);
}

        /* other methods */

Cure* Cure::clone()
{
    return (new Cure(_type));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target << "'s wounds *" << std::endl;
}
