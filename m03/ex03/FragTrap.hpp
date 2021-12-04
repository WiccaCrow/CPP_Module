#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        /* Constructs and destructs */
        FragTrap(void);
        FragTrap(std::string name_in);
        FragTrap(std::string name_in, int hp_in);
        FragTrap(std::string name_in, int hp_in, int en_p_in);
        FragTrap(std::string name_in, int hp_in, int en_p_in, int att_in);
        ~FragTrap();

        /* methods */
        void highFivesGuys(void);
};

#endif