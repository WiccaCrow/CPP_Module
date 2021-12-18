#include "Character.hpp"

/******************************************************************************/
/* Constructors */

//      init
Character::Character(std::string name) :
                    _Name (name)
{
    std::cout << "Character:   " << getName() << "   constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _inventory[i] = 0;
    garbage_collector = NULL;
}

//      copy

Character::Character(const Character &obj)
{
    std::cout << "Character: " << getName() << " copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

void	Character::ft_lstclear(t_unequip **lst)
{
    std::cout << "Character: " << getName() << " clean garbage collector for AMateria after unequip" << std::endl;
	t_unequip	*ptr;

	ptr = *lst;
	while (ptr)
	{
		ptr = (*lst)->next;
        delete (*lst)->tmp_mtr;
        delete *lst;
		*lst = ptr;
	}
	if (lst)
		lst = NULL;
}

Character::~Character()
{
    std::cout << "Character:    " << getName() << "       destructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        if (_inventory[i])
            delete _inventory[i];
    if (garbage_collector != NULL)
        ft_lstclear (&garbage_collector);
    else
        std::cout << "\033[95m is NULL\n\033[0m";
}

/******************************************************************************/
/* Operators */

//      =

Character &   Character::operator=(const Character &obj)
{
    std::cout << "Character:  " << getName() << "  Assignation operator called " << std::endl;
    if (this != &obj)
    {
        _Name = obj.getName();
garbage_collector = obj.garbage_collector;
        for (int i = 0; i < 4; ++i)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (_inventory[i])
                _inventory[i] = obj._inventory[i]->clone();
            else
                _inventory[i] = 0;
        }
    }
    return (*this);
}

/******************************************************************************/
/* Private functions */

Character::t_unequip	*Character::ft_lstnew(AMateria *content)
{
	t_unequip	*new_list;

    new_list = new t_unequip;
	new_list->tmp_mtr = content;
	new_list->next = NULL;
	return (new_list);
}

void	Character::ft_lstadd_front(t_unequip **lst, t_unequip *new_lst)
{
	if (lst)
	{
		if (*lst)
			new_lst->next = *lst;
		*lst = new_lst;
	}
}

/******************************************************************************/
/* Public functions */

        /* Set atributs */

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!_inventory[i])
        {
                                                                                        // if (garbage_collector != NULL)
                                                                                        // std::cout << "\033[96m NOT NULL\n\033[0m";
            _inventory[i] = m->clone();
                                                                                    //         if (garbage_collector != NULL)
                                                                                    // std::cout << "\033[96m NOT NULL\n\033[0m";
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >=0 && idx < 4 && _inventory[idx])
    {
        if (garbage_collector)
            ft_lstadd_front(&garbage_collector, ft_lstnew(_inventory[idx]));
        else
            garbage_collector = ft_lstnew(_inventory[idx]);
        _inventory[idx] = 0;
    }
}

        /* Get and show atributs */

void    Character::show_all(void)
{
    std::cout << "name:      " << getName() << std::endl;
    std::cout << "inventory: " << std::endl;
    for (int i = 0; i < 4; ++i)
        if (_inventory[i])
            std::cout << "           slot " << i << ": " << _inventory[i]->getType() << std::endl;
}

std::string const & Character::getName() const
{
    return (_Name);
}

        /* other methods */

void Character::use(int idx, ICharacter& target)
{
    if (idx >=0 && idx < 4 && _inventory[idx])
    {
        _inventory[idx]->use(target);
    }
}
