#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class   Zombie 
{
    private:
        const std::string name;

    public:
        Zombie(std::string &name_in);
        Zombie(void);
        ~Zombie(void);
        void    announce(void);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif