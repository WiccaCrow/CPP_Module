#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    private:
        bool guardGateMode;
    public:
        /* Constructs and destructs */
        ScavTrap(void);
        ScavTrap(std::string name_in);
        ScavTrap(const char * name_in);
        // ScavTrap(std::string name_in, int hp, int en_p, int att_dam, bool gGMode);
        // ScavTrap(const char * name_in, int hp, int en_p, int att_dam, bool gGMode);
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