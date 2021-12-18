#include "FragTrap.hpp"

/******************************************************************************/
/* Constructors */

//      init

FragTrap::FragTrap(void) : ClapTrap()
{
    Hitpoints = 100; 
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap:    constructor called" << std::endl;
    ShowAll();
}

FragTrap::FragTrap(std::string name_in) : ClapTrap()
{
    Name = name_in;
    Hitpoints = 100; 
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap:    constructor called" << std::endl;
    ShowAll();
}

FragTrap::FragTrap(std::string name_in, int hp_in) : ClapTrap()
{
    Name = name_in;
    Hitpoints = hp_in; 
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap:    constructor called" << std::endl;
    ShowAll();
}

FragTrap::FragTrap(std::string name_in, int hp_in, int en_p_in) : ClapTrap()
{
    Name = name_in;
    Hitpoints = hp_in; 
    Energy_points = en_p_in;
    Attack_damage = 30;
    std::cout << "FragTrap:    constructor called" << std::endl;
    ShowAll();
}
FragTrap::FragTrap(std::string name_in, int hp_in, int en_p_in, int att_in) : ClapTrap()
{
    Name = name_in;
    Hitpoints = hp_in; 
    Energy_points = en_p_in;
    Attack_damage = att_in;
    std::cout << "FragTrap:    constructor called" << std::endl;
    ShowAll();
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