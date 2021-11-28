#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap ostrich("ostrich");
    ClapTrap Lion = ostrich;
    Lion = ClapTrap("Lion");

    std::cout << "________________________________" << std::endl;

    Lion.attack(ostrich.GetName());
    std::cout << "The " << Lion.GetName() << " found a nail file and sharpened his claws." << std::endl;
    Lion.increaseAttack(2);


    Lion.attack(ostrich.GetName());
    ostrich.takeDamage(Lion.GetAttack());
    std::cout << "________________________________" << std::endl;

    std::cout << "The " << ostrich.GetName() << " flees. He ran to the oasis and found a stream among the tall cacti. The ostrich drank water from the stream. The water had a healing effect." << std::endl;
    ostrich.beRepaired(1);


    return (0);
}