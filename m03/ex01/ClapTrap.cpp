#include "ClapTrap.hpp"

/******************************************************************************/
/* Constructors */

//      init 

ClapTrap::ClapTrap(std::string name_in, int hp, int en_p, int att_dam) :
        Name (name_in), Hitpoints (hp), Energy_points (en_p), Attack_damage (att_dam)
{
    std::cout << "________________________________" << std::endl;
    std::cout << "|ClapTrap:    constructor called" << std::endl;
    ShowAll();
    std::cout << "|_______________________________" << std::endl;
}

ClapTrap::ClapTrap(const char * name_in, int hp, int en_p, int att_dam) :
        Name (name_in), Hitpoints (hp), Energy_points (en_p), Attack_damage (att_dam)
{
    std::cout << "________________________________" << std::endl;
    std::cout << "|ClapTrap:    constructor called" << std::endl;
    ShowAll();
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
    SetAll(obj.Name, obj.Hitpoints, obj.Energy_points, obj.Attack_damage);
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set private members*/
void        ClapTrap::SetAll(std::string name_in, int hp, int en_p, int att_dam)
{
    SetName(name_in);
    SetHitpoints(hp);
    SetEnergy_points(en_p);
    SetAttack(att_dam);
}

void        ClapTrap::SetAll(char * name_in, int hp, int en_p, int att_dam)
{
    SetName(name_in);
    SetHitpoints(hp);
    SetEnergy_points(en_p);
    SetAttack(att_dam);
}

void        ClapTrap::SetName(std::string name_in)
{
    Name = name_in;
}

void        ClapTrap::SetName(const char * name_in)
{
    Name = name_in;
}

void         ClapTrap::SetHitpoints(int hp)
{
    Hitpoints = hp;
}

void         ClapTrap::SetEnergy_points(int en_p)
{
    Energy_points = en_p;
}

void    ClapTrap::SetAttack(int att_dam)
{
    Attack_damage = att_dam;
}

        /* Get and show private members*/

void    ClapTrap::ShowAll(void) const
{
    std::cout << "|_______________________________" << std::endl;
    std::cout << "|         Name is          " << GetName() << std::endl;
    std::cout << "|         Hitpoints is     " << GetHitpoints() << std::endl;
    std::cout << "|         Energy points is " << GetEnergy_points() << std::endl;
    std::cout << "|         Attack damage is " << GetAttack() << std::endl;
    std::cout << "|_______________________________" << std::endl;
}

std::string ClapTrap::GetName(void) const
{
    return (Name);
}

int ClapTrap::GetHitpoints(void) const
{
    return (Hitpoints);
}

int ClapTrap::GetEnergy_points(void) const
{
    return (Energy_points);
}

int ClapTrap::GetAttack(void) const
{
    return (Attack_damage);
}

        /* other methods */

void ClapTrap::attack(String_my const & target)
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

void ClapTrap::increaseAttack(unsigned int amount)
{
    std::cout << "ClapTrap " << Name << " Attack increased by " << amount << " units. ";
    Attack_damage += amount;
    std::cout << Name << " attck is " << Attack_damage << "." << std::endl;
}
