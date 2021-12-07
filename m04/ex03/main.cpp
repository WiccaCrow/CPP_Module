#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"


void    test_class_AMateria(void)
{
    // AMateria    Ice;
    // AMateria    Cure;
}

void    test_main(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

    // ICharacter* me = new Character("me");

    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);    
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // ICharacter* bob = new Character("bob");

    // me->use(0, *bob);
    // me->use(1, *bob);

    // delete bob;
    // delete me;
    delete src;
}

int main(void)
{
    test_class_AMateria();
    test_main();
    return (0);
}