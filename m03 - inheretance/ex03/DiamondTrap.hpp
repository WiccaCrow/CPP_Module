#ifndef DIAMOND_HPP
# define DIAMOND_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        String_my   Name;

    public:
        DiamondTrap(std::string name_in);
        ~DiamondTrap();

        using ScavTrap::attack;

        void whoAmI();
};

#endif