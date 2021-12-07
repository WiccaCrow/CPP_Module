#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"


class AMateria
{
    protected:
        std::string _type;
    public:
        /* Constructs and destructs*/
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(const AMateria &obj);
        ~AMateria();

        /* operators */
        AMateria    &operator=(const AMateria &obj);

        /* Set atributs */
        /* Get and show atributs */
        std::string const & getType() const; //Returns the materia type

        /* other methods */
        virtual AMateria* clone() const = 0;
        // virtual void use(ICharacter& target);
};

#endif