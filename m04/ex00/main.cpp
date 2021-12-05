#include <iostream>
#include "ClassAnimal.hpp"
#include "ClassDog.hpp"
#include "ClassCat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

void    test_name_cout_color(const char * color, const std::string text = "test")
{
    std::cout << color << "  _____________________________________" << std::endl;
    std::cout << "  ||  " << text << std::endl;
    std::cout << "  || \n  \\/ " << "\033[0m" << std::endl;
}

void    test_wrong_class()
{
    std::cout << "\n\x1b[30;42m" << "test_wrong_class" << "\x1b[0m" << std::endl;
    test_name_cout_color("\033[92m", "\tconst WrongAnimal* meta = new WrongAnimal();\n\tconst WrongAnimal* i = new WrongCat();");
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* i = new WrongCat();

    test_name_cout_color("\033[92m", "\ti->getType();");
    std::cout << i->getType() << " " << std::endl;

    test_name_cout_color("\033[92m", "\tmakeSound");
    std::cout << "\033[36m    i->makeSound();    \033[0m\n\n";
    i->makeSound();
    std::cout << "\033[36m    meta->makeSound();    \033[0m\n\n";
    meta->makeSound();

    std::cout << "\033[36m    delete meta,i    \033[0m\n\n";
    delete meta;
    delete i;

    std::cout << "\033[36m    WrongCat wc;\n    wc.makeSound();    \033[0m\n\n";
    WrongCat wc;
    wc.makeSound();

    std::cout << "\033[36m    end of block    \033[0m\n\n";
}

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;

    test_wrong_class();
    return (0);
}
