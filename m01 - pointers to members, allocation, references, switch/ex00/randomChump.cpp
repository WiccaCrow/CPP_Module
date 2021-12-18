#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie stack_zombie(name);
    stack_zombie.announce();
    std::cout <<  "2.2. Exit the block in which the Zombie_stack was created." << std::endl;
}