#include "Character.hpp"

/******************************************************************************/
/* Constructors */

//      init
Character::Character(std::string name) :
                    _Name (name)
{
    std::cout << "Character:      constructor called" << std::endl;
}

//      copy

Character::Character(const Character &obj)
{
    std::cout << "Character: copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

Character::~Character()
{
    std::cout << "Character:       destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

Character &   Character::operator=(const Character &obj)
{
    std::cout << "Character:    Assignation operator called " << std::endl;
    if (this != &obj)
    {
        _Name = obj.getName();
    }
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

void    Character::show_all(void)
{
    std::cout << getName() << std::endl;
}

std::string const & Character::getName() const
{
    return (_Name);
}

        /* other methods */


// Character* Character::clone()
// {
//     return (new Character(_type));
// }
