#include "DiamondTrap.hpp"

/******************************************************************************/
/* Constructors */

//      init

DiamondTrap::DiamondTrap(std::string name_in) : 
                            FragTrap("FT"), ScavTrap("ST")
{
    std::cout << "DiamondTrap:    constructor called" << std::endl;
    this->Name = name_in;
    ClapTrap::Name = name_in + "_clap_name";
    this->Hitpoints = FragTrap::Hitpoints;
    this->Energy_points = ScavTrap::Energy_points;
    this->Attack_damage = FragTrap::Attack_damage;

    std::cout << "Name:           " << Name << std::endl;
    std::cout << "Claptrap::Name: " << ClapTrap::Name << std::endl;
    std::cout << "Hitpoints:      " << Hitpoints << std::endl;
    std::cout << "Energy points:  " << Energy_points << std::endl;
    std::cout << "Attack damage:  " << Attack_damage << std::endl;

    // std::cout << "FT:  Energy points: " << FragTrap::Energy_points << std::endl;

    // std::cout << "Claptrap::Hitpoints: " << ClapTrap::Hitpoints << std::endl;
    // ClapTrap::Hitpoints = 100001100;
    // std::cout << "Claptrap::Hitpoints: " << ClapTrap::Hitpoints << std::endl;
}

/******************************************************************************/
/* Destructors */

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: destructor called" << std::endl;
}

/******************************************************************************/
/* Public functions */

void DiamondTrap::whoAmI()
{
    std::cout << "clapTrap name:    " << GetName() << std::endl;
    std::cout << "DiamondTrap name: " << Name << std::endl;
}
