#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string Name;
        int         Hitpoints;
        int         Energy_points;
        int         Attack_damage;

    public:
        ClapTrap(std::string name_in = "None", int hp = 10, int en_p = 10, int att_dam = 0);
        ClapTrap(const ClapTrap &obj);
        ~ClapTrap();

        ClapTrap &  operator=(const ClapTrap &obj);

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string GetName(void);
        int GetAttack(void);
        void increaseAttack(unsigned int amount);

};

#endif
