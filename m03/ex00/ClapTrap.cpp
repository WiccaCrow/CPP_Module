#include "ClapTrap.hpp"

/******************************************************************************/
/* Constructors */

//      init 

ClapTrap::ClapTrap(std::string name_in, int hp, int en_p, int att_dam) :
        Name (name_in), Hitpoints (hp), Energy_points (en_p), Attack_damage (att_dam)
{
    std::cout << "________________________________" << std::endl;
    std::cout << "|ClapTrap:    constructor called" << std::endl;
    std::cout << "|         Name is          " << Name << std::endl;
    std::cout << "|         Hitpoints is     " << Hitpoints << std::endl;
    std::cout << "|         Energy points is " << Energy_points << std::endl;
    std::cout << "|         Attack damage is " << Attack_damage << std::endl;
    std::cout << "|_______________________________" << std::endl;
}

//      copy

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "ClapTrap:    Copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap:    destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

ClapTrap &  ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap:    Assignation operator called " << std::endl;
    if (this == &obj)
        return (*this);
    Name = obj.Name;
    Hitpoints = obj.Hitpoints;
    Energy_points = obj.Energy_points;
    Attack_damage = obj.Attack_damage;
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

void ClapTrap::attack(std::string const & target)
{
    std::cout << "ClapTrap " << Name << " attack " << target << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << Name << " takes " << amount << " amount damage. ";
    Hitpoints -= amount;
    std::cout << "Now hitpoints of " << Name << " is " << Hitpoints << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << Name << " regenerates " << amount << " amount health points.";
    Hitpoints += amount;
    std::cout << "Now hitpoints of " << Name << " is " << Hitpoints << "." << std::endl;
}

std::string ClapTrap::GetName(void)
{
    return (Name);
}

int ClapTrap::GetAttack(void)
{
    return (Attack_damage);
}

void ClapTrap::increaseAttack(unsigned int amount)
{
    std::cout << "ClapTrap " << Name << " Attack increased by " << amount << " units. ";
    Attack_damage += amount;
    std::cout << Name << " attck is " << Attack_damage << "." << std::endl;
}
