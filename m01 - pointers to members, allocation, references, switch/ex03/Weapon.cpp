#include "Weapon.hpp"

/******************************************************************************/
/* Constructors */

Weapon::Weapon(std::string name) :
                      str (name)
{}

/******************************************************************************/
/* Destructors */

Weapon::~Weapon(void) {}

/******************************************************************************/
/* Public functions */

const std::string &    Weapon::getType(void)
{
    return (str);
}

void    Weapon::setType(std::string name)
{
    str = name;
}