#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void    test_h1lvl_cout_green_color(const std::string text = "test")
{
    std::cout << "\n\x1b[30;42m" << text << "\x1b[0m" << std::endl;
}

void    test_h2lvl_cout_green_color(const std::string text = "test")
{
    std::cout << "\033[92m" << "  _____________________________________" << std::endl;
    std::cout << "  ||  " << text << std::endl;
    std::cout << "  || \n  \\/ " << "\033[0m" << std::endl;
}

void    test_h3lvl_cout_blue_color(const std::string text = "test")
{
    std::cout << std::endl << "\033[36m" << text << "\n\033[0m";
}

void    test_class_AMateria(void)
{
    test_h1lvl_cout_green_color("test_class_AMateria");
    test_h3lvl_cout_blue_color("AMateria *tmp_ice = new Ice();");
    AMateria *tmp_ice = new Ice();
    test_h3lvl_cout_blue_color("AMateria *tmp_cure = new Cure();");
    AMateria *tmp_cure = new Cure();
    test_h3lvl_cout_blue_color("Cure test_cure;");
    Cure test_cure;
    test_h3lvl_cout_blue_color("std::cout << tmp_cure->getType() << std::endl;");
    std::cout << tmp_cure->getType() << std::endl;
    test_h3lvl_cout_blue_color("std::cout << tmp_ice->getType() << std::endl;");
    std::cout << tmp_ice->getType() << std::endl;
    test_h3lvl_cout_blue_color("delete tmp_cure;");
    delete tmp_cure;
    test_h3lvl_cout_blue_color("delete tmp_ice;");
    delete tmp_ice;
}

void    test_main(void)
{
    test_h1lvl_cout_green_color("test_main");
    test_h2lvl_cout_green_color("    IMateriaSource* src = new MateriaSource();");
    IMateriaSource* src = new MateriaSource();
    test_h2lvl_cout_green_color("    src->learnMateria(new Ice());");
    src->learnMateria(new Ice());
    test_h2lvl_cout_green_color("    src->learnMateria(new Cure());");
    src->learnMateria(new Cure());

    test_h2lvl_cout_green_color("    ICharacter* me = new Character(\"me\");");
    ICharacter* me = new Character("me");

    test_h2lvl_cout_green_color("    AMateria* tmp;\n          tmp = src->createMateria(\"ice\");");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    test_h2lvl_cout_green_color("    me->equip(tmp);");
    me->equip(tmp);
    test_h2lvl_cout_green_color("    tmp = src->createMateria(\"cure\");");
    tmp = src->createMateria("cure");
    test_h2lvl_cout_green_color("    me->equip(tmp);");
    me->equip(tmp);

    test_h2lvl_cout_green_color("    ICharacter* bob = new Character(\"bob\");");
    ICharacter* bob = new Character("bob");

    test_h2lvl_cout_green_color("    me->use(0, *bob);");
    me->use(0, *bob);
    test_h2lvl_cout_green_color("    me->use(1, *bob);");
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

int main(void)
{
    // test_class_AMateria();
    test_main();
    return (0);
}