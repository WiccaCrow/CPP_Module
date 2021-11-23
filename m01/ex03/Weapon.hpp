#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Weapon
{
    private:
        std::string str;
    public:
        Weapon(std::string name = "none");
        ~Weapon(void);

        const std::string & getType(void);
        void                setType(std::string name);
};

#endif