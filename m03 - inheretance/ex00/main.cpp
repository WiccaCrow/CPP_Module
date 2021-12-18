#include "ClapTrap.hpp"

void    test_name_cout_color(const String_my color, const String_my text = "test")
{
    std::cout << color << "  _____________________________________" << std::endl;
    std::cout << "  ||  " << text << std::endl;
    std::cout << "  || \n  \\/ " << "\033[0m" << std::endl;
}

int main( void )
{
    std::cout << "\n\x1b[30;42m" << "  TEST CLAP_TRAP " << "\x1b[0m" << std::endl;

    test_name_cout_color("\033[92m", "Yes. It work with NULLptr too ;-)");
    ClapTrap nullptr_give(0);

    test_name_cout_color("\033[92m", "void. no entry");
    ClapTrap void_give;

    test_name_cout_color("\033[92m", "test ClapTrap: \033[35m create, copy\033[92m");
    ClapTrap ostrich("ostrich");
    ClapTrap Lion = ostrich;
    Lion = ClapTrap("Lion");

    test_name_cout_color("\033[92m", "test ClapTrap: \033[35m attack, GetName, takeDamage \033[92m");
    Lion.attack(ostrich.GetName());
    std::cout << "The " << Lion.GetName() << " found a nail file and sharpened his claws." << std::endl;
    Lion.increaseAttack(2);
    Lion.attack(ostrich.GetName());
    ostrich.takeDamage(Lion.GetAttack());

    test_name_cout_color("\033[92m", "test ClapTrap: \033[35m beRepaired, GetName \033[92m");
    std::cout << "The " << ostrich.GetName() << " flees. He ran to the oasis and found a stream among the tall cacti. The ostrich drank water from the stream. The water had a healing effect." << std::endl;
    ostrich.beRepaired(1);
    std::cout << std::endl;

    return (0);
}