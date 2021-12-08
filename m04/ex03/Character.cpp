#include "Character.hpp"

/******************************************************************************/
/* Constructors */

//      init
Character::Character(std::string name) :
                    _Name (name)
{
    std::cout << "Character:      constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
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
        for (int i = 0; i < 4; ++i)
        {
            if (_inventory[i])
                delete _inventory[i];
            _inventory[i] = obj.get_inventory_i_clone(i);
        }
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

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
    }
}

AMateria *   Character::get_inventory_i_clone(int i) const
{
    if (_inventory[i])
        return (_inventory[i]->clone());
    return (0);
}

void Character::use(int idx, ICharacter& target)
{
    if (_inventory[idx])
    {
        _inventory[idx]->use(target);
    }
}