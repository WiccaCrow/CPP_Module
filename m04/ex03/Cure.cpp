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

Cure::Cure(const Cure &obj) :
                    AMateria("cure")
{
    std::cout << "Cure: copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

Cure::~Cure()
{
    std::cout << "Cure:       destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

Cure &   Cure::operator=(const Cure &obj)
{
    std::cout << "Cure:    Assignation operator called " << std::endl;
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

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
