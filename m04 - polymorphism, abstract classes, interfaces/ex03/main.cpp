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
    test_h3lvl_cout_blue_color("    AMateria    *Ice_ptr = new Ice();");
    AMateria    *Ice_ptr = new Ice();
    test_h3lvl_cout_blue_color("    AMateria    *Cure_ptr = new Cure();");
    AMateria    *Cure_ptr = new Cure();

    test_h1lvl_cout_green_color("test_main");
    test_h2lvl_cout_green_color("    IMateriaSource* src = new MateriaSource();");
    IMateriaSource* src = new MateriaSource();
    test_h2lvl_cout_green_color("    src->learnMateria(new Ice());");
    src->learnMateria(Ice_ptr);
    test_h2lvl_cout_green_color("    src->learnMateria(new Cure());");
    src->learnMateria(Cure_ptr);

    test_h2lvl_cout_green_color("    ICharacter* me = new Character(\"me\");");
    ICharacter* me = new Character("me");
    test_h2lvl_cout_green_color("    AMateria* tmp;\n          tmp = src->createMateria(\"ice\");");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    test_h2lvl_cout_green_color("    me->equip(tmp);");
    me->equip(tmp);
    test_h2lvl_cout_green_color("    delete tmp;");
    delete tmp;
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

    test_h2lvl_cout_green_color("    delete bob;");
    delete bob;
    test_h2lvl_cout_green_color("    delete me;");
    delete me;
    test_h2lvl_cout_green_color("    delete src;");
    delete src;
    test_h3lvl_cout_blue_color("    delete Ice_ptr;");
    delete Ice_ptr;
    test_h3lvl_cout_blue_color("    delete Cure_ptr;");
    delete Cure_ptr;
    test_h2lvl_cout_green_color("    delete tmp;");
    delete tmp;

    test_h2lvl_cout_green_color("    deep");
    test_h3lvl_cout_blue_color("    Character deep1(\"deep_1\");");
    {
        Character deep1("deep_1");
        {
            test_h3lvl_cout_blue_color("    {\n        Character deep2(\"deep_2\");\n        deep1 = deep2;");
            Character deep2("deep_2");
            deep1 = deep2;
            test_h3lvl_cout_blue_color("    }");
        }
        test_h3lvl_cout_blue_color("    deep1.show_all();");
        deep1.show_all();
    }

    {
        test_h2lvl_cout_green_color("    Character equip/unequip");
        Ice ice_obj;
        Cure cure_obj;
        
        test_h3lvl_cout_blue_color("Character ice_man(\"ice_man\");");
        Character ice_man("ice_man");
        
        test_h3lvl_cout_blue_color("        for (int i = 0; i < 6; ++i)\n            ice_man.equip(&ice_obj);\n        ice_man.show_all();");
        for (int i = 0; i < 6; ++i)
            ice_man.equip(&ice_obj);
        ice_man.show_all();

        test_h3lvl_cout_blue_color("        ice_man.unequip(5); ice_man.unequip(2); ice_man.unequip(2); ice_man.unequip(3);\n        ice_man.show_all();");
        ice_man.unequip(5);
        ice_man.unequip(2);
        ice_man.unequip(2);
        ice_man.unequip(3);
        ice_man.show_all();

        test_h3lvl_cout_blue_color("        ice_man.equip(&cure_obj);\n        ice_man.show_all();");
        ice_man.equip(&cure_obj);
        ice_man.show_all();
        test_h3lvl_cout_blue_color("        end of block");
    }
}

int main(void)
{
    test_class_AMateria();
    test_main();
    // while (1);
    return (0);
}