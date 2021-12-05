#include "FragTrap.hpp"

/******************************************************************************/
/* Constructors */

//      init

FragTrap::FragTrap(std::string name_in, int hp_in, int en_p_in, int att_in) : 
                    ClapTrap(name_in,     hp_in,     en_p_in,     att_in)
{
    std::cout << "FragTrap:    constructor called" << std::endl;
}

/******************************************************************************/
/* Destructors */

FragTrap::~FragTrap()
{
    std::cout << "FragTrap:    destructor called" << std::endl;
}

/******************************************************************************/
/* Public functions */

void FragTrap::highFivesGuys(void)
{
    std::cout << GetName() << " request: \"\033[33mHigh fives! ;-)\033[0m\"" << std::endl;
}

void    FragTrap::attack(String_my const & target)
{
    std::cout << "FragTrap attack: ";
    ClapTrap::attack(target);
}