#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "ClassString_my.hpp"

#include <iostream>

class ClapTrap
{
    private:
        String_my   Name;
        int         Hitpoints;
        int         Energy_points;
        int         Attack_damage;

    public:
        /* Constructs and destructs */
        ClapTrap(std::string name_in = "none", int hp = 10, int en_p = 10, int att_dam = 0);
        ClapTrap(const char * name_in, int hp = 10, int en_p = 10, int att_dam = 0);
        ClapTrap(const ClapTrap &obj);
        ~ClapTrap();

        /* operators */
        ClapTrap &  operator=(const ClapTrap &obj);

        /* Set private members */
        void        SetAll(std::string name_in, int hp, int en_p, int att_dam);
        void        SetAll(char * name_in, int hp, int en_p, int att_dam);
        void        SetName(std::string name_in);
        void        SetName(const char * name_in);
        void        SetHitpoints(int hp);
        void        SetEnergy_points(int en_p);
        void        SetAttack(int att_dam);

        /* Get and show private members */
        void        ShowAllClapTrap(void) const;
        std::string GetName(void) const;
        int         GetHitpoints(void) const;
        int         GetEnergy_points(void) const;
        int         GetAttack(void) const;

        /* other methods */
        void    attack(String_my const & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    increaseAttack(unsigned int amount);
};

#endif
