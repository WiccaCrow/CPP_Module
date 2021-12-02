#include "ScavTrap.hpp"

/******************************************************************************/
/* Constructors */

//      init 

ScavTrap::ScavTrap(std::string name_in, int hp, int en_p, int att_dam, bool gGMode) :
          ClapTrap (name_in, hp, en_p, att_dam), guardGateMode (gGMode)
{
    std::cout << "________________________________" << std::endl;
    std::cout << "|ScavTrap:    constructor called" << std::endl;
    ShowAllScavTrap();
    std::cout << "|_______________________________" << std::endl;
}

ScavTrap::ScavTrap(const char * name_in, int hp, int en_p, int att_dam, bool gGMode) :
          ClapTrap (name_in, hp, en_p, att_dam), guardGateMode (gGMode)
{
    std::cout << "________________________________" << std::endl;
    std::cout << "|ScavTrap:    constructor called" << std::endl;
    ShowAllScavTrap();
    std::cout << "|_______________________________" << std::endl;
}

//      copy

ScavTrap::ScavTrap(const ScavTrap &obj) : 
          ClapTrap(obj.GetName(),          obj.GetHitpoints(), 
                   obj.GetEnergy_points(), obj.GetAttack()), guardGateMode (obj.GetGuardGateMode())
{
    std::cout << "________________________________" << std::endl;
    std::cout << "|ScavTrap:    Copy constructor called" << std::endl;
    ShowAllScavTrap();
    std::cout << "|_______________________________" << std::endl;
    /* Sets new members of ScavTrap class: */
}

/******************************************************************************/
/* Destructors */

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap:    destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

ScavTrap &  ScavTrap::operator=(const ScavTrap &obj)
{
    std::cout << "ScavTrap:    Assignation operator called " << std::endl;
    if (this == &obj)
        return (*this);
    SetAll(obj.GetName(), obj.GetHitpoints(), obj.GetEnergy_points(), obj.GetAttack());
    SetGuardGateMode (obj.GetGuardGateMode());
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set private members*/
void    ScavTrap::SetGuardGateMode(bool mode)
{
    guardGateMode = mode;
}

        /* Get and show private members*/
bool    ScavTrap::GetGuardGateMode(void) const 
{
    return (guardGateMode);
}

void    ScavTrap::ShowAllScavTrap(void)
{
    ShowAllClapTrap();
    ShowGuardGateMode();
    std::cout << "|_______________________________" << std::endl;
}

void    ScavTrap::ShowGuardGateMode(void)
{
    std::cout << "|         GuardGateMode is " << GetGuardGateMode() << std::endl;
}

        /* other methods */
void ScavTrap::guardGate(void)
{
    // SetGuardGateMode(true);
    std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}
