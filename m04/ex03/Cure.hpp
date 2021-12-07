#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        /* Constructs and destructs*/
        Cure(void);
        Cure(const Cure &obj);
        ~Cure();

        /* operators */
        Cure    &operator=(const Cure &obj);

        /* Set atributs */
        /* Get and show atributs */
        /* other methods */
        virtual Cure* clone();
        virtual void use(ICharacter& target);
};

#endif