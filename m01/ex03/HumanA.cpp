#include "HumanA.hpp"

/******************************************************************************/
/* Constructors */
HumanA::HumanA(std::string name_in, Weapon &weapon_in) : 
                   name (name_in),        weapon (weapon_in)
{}

/******************************************************************************/
/* Destructors */
HumanA::~HumanA(void)
{}

/******************************************************************************/
/* Public functions */
void    HumanA::attack(void)
{
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}