#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        bool guardGateMode;
    public:
        /* Constructs and destructs */
        ScavTrap(std::string name_in = "no_name", int hp = 100, 
                 int en_p = 50, int att_dam = 20, bool gGMode = false);
        ScavTrap(const char * name_in, int hp = 100, 
                 int en_p = 50, int att_dam = 20, bool gGMode = false);
        ScavTrap(const ClapTrap &obj);
        ScavTrap(const ScavTrap &obj);
        ~ScavTrap();

        /* operators */
        ScavTrap &  operator=(const ScavTrap &obj);

        /* Set private members*/
        void    SetAll(std::string name_in, int hp, int en_p, int att_dam, bool gGMode);
        void    SetAll(char * name_in, int hp, int en_p, int att_dam, bool gGMode);
        void    SetGuardGateMode(bool mode);

        /* Get and show private members*/
        bool    GetGuardGateMode(void) const;
        void    ShowAll(void) const;
        void    ShowGuardGateMode(void) const;

        /* other methods */
        void guardGate(void);
};

#endif