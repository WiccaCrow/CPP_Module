#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        /* Constructs and destructs */
        FragTrap(std::string name_in = "no name", int hp_in = 100, int en_p_in = 100, int att_in = 30);
        ~FragTrap();

        /* methods */
        void highFivesGuys(void);
};

#endif