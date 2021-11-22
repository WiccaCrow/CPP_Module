#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class   Zombie 
{
    private:
        std::string name;

    public:
        Zombie(std::string &name_in);
        Zombie(void);
        ~Zombie(void);
        void    announce(void);
};

void    randomChump( std::string name );
Zombie* newZombie( std::string name );
void    input_name_for_create_on_heap(std::string &name_input);
void    heap_zombie_use_and_delete(std::string &name, Zombie* &heap_zombie);

#endif