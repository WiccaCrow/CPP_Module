#include <Zombie.hpp>

Zombie::Zombie(std::string &name_in) : name(name_in)
{

}

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
    std::cout << name << " zombie closed." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}