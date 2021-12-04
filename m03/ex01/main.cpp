#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

void    test_name_cout_color(const char * color, const String_my text = "test")
{
    std::cout << color << "  _____________________________________" << std::endl;
    std::cout << "  ||  " << text << std::endl;
    std::cout << "  || \n  \\/ " << "\033[0m" << std::endl;
}

void    test_ClapTrap( void )
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
}

void    test_ScavTrap(void)
{
    std::cout << "\n\x1b[30;42m" << "  TEST SCAV_TRAP " << "\x1b[0m" << std::endl;

    {
        test_name_cout_color("\033[92m", "Yes. It work with NULLptr too ;-)");
        ScavTrap nullptr_give(0);
        std::cout << "\033[36m    End of blosk.    \033[0m\n\n";
    }

    {
        test_name_cout_color("\033[92m", "void. no entry");
        ScavTrap void_give;
        std::cout << "\033[36m    End of blosk.    \033[0m\n\n";
    }

    {
        test_name_cout_color("\033[92m", "test ScavTrap: \033[35m create, copy\033[92m");
        std::cout << "\033[33m    ScavTrap ostrich(\"ostrich\");    \033[0m\n";
        ScavTrap ostrich("ostrich");

        std::cout << "\n\033[33m    ostrich set Guard Gate Mode true and show;    \033[0m\n";
        ostrich.SetGuardGateMode(true);
        ostrich.ShowGuardGateMode();

        std::cout << "\n\033[33m    ScavTrap Lion = ostrich;    \033[0m\n";
        ScavTrap Lion = ostrich;

        test_name_cout_color("\033[92m", "test ScavTrap: \033[35m get/set\033[92m");
        std::cout << "\033[33m    ostrich set Guard Gate Mode false and show;    \033[0m\n";
        Lion.SetGuardGateMode(false);
        Lion.ShowGuardGateMode();

        test_name_cout_color("\033[92m", "test ScavTrap: \033[35m operator=\033[92m");
        std::cout << "\033[33m    ClapTrap Lion2 = Lion;    \033[0m\n";
        ClapTrap Lion2 = Lion;
        Lion2.ShowAll();
        
        std::cout << "\033[33m    Lion = ScavTrap(\"Lion\");    \033[0m\n";
        Lion = ScavTrap("LionKing");

        std::cout << "\033[33m    ostrich = Lion;    \033[0m\n";
        ostrich = Lion;
        ostrich.ShowAll();
    
        test_name_cout_color("\033[92m", "test ScavTrap: \033[35m guardGate\033[92m");
        std::cout << "\033[33m    Lion.guardGate();    \033[0m\n";
        Lion.guardGate();
        std::cout << "\n\033[36m    End of blosk.    \033[0m\n\n";
    }
        std::cout << "\033[34m    End. Thank you for the attention.    \033[0m\n";
}

int main (void)
{
    test_ClapTrap();
    test_ScavTrap();
}