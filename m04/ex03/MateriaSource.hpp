#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        virtual ~MateriaSource();
        virtual void learnMateria(AMateria*);
    //     virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif