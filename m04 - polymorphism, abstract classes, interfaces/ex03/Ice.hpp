#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        /* Constructs and destructs*/
        Ice(void);
        Ice(const Ice &obj);
        ~Ice();

        /* operators */
        Ice    &operator=(const Ice &obj);

        /* Set atributs */
        /* Get and show atributs */
        /* other methods */
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif