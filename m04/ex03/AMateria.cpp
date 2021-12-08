#include "AMateria.hpp"

/******************************************************************************/
/* Constructors */

//      init
AMateria::AMateria(void)
{
    std::cout << "AMateria:      constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) :
                                _type (type)
{
    std::cout << "AMateria:      constructor called" << std::endl;
}

//      copy

AMateria::AMateria(const AMateria &obj)
{
    std::cout << "AMateria: copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

AMateria::~AMateria()
{
    std::cout << "AMateria:       destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

AMateria &   AMateria::operator=(const AMateria &obj)
{
    std::cout << "AMateria:    Assignation operator called " << std::endl;
    if (this != &obj)
    {}
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

std::string const & AMateria::getType() const
{
    return (_type);
}

        /* other methods */

void AMateria::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
