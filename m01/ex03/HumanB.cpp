#include "HumanB.hpp"

/******************************************************************************/
/* Constructors */
HumanB::HumanB(std::string name_in) :
                   name (name_in)
{}

/******************************************************************************/
/* Destructors */
HumanB::~HumanB(void)
{}

/******************************************************************************/
/* Public functions */
void    HumanB::attack(void)
{
    std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}

void   HumanB::setWeapon(Weapon &weapon_in)
{
    weapon = &weapon_in;
}