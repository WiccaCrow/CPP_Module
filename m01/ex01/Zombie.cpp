#include <Zombie.hpp>

Zombie::Zombie(std::string &name_in) : name(name_in)
{
    std::cout << "with name constructor called" << std:: endl;
}

Zombie::Zombie(void)
{
    std::cout << "default constructor called" << std:: endl;
}

Zombie::~Zombie(void)
{
    std::cout << name << " zombie closed." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}