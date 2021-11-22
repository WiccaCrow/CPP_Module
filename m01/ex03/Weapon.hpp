#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Weapon
{
    private:
        std::string str;
    public:
        std::string &getType();
        void    setType();
};

#endif