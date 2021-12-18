#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon      &weapon;
    public:
        HumanA(std::string name_in, Weapon &weapon_in);
        ~HumanA(void);

        void    attack(void);
};

#endif
