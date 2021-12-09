#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *_Source[4];
    public:
        /* Constructs and destructs*/
        MateriaSource();
        MateriaSource(const MateriaSource &obj);
        virtual ~MateriaSource();

        /* operators */
        MateriaSource &   operator=(const MateriaSource &obj);

        /* Set atributs */
        /* Get and show atributs */

        /* other methods */
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};

#endif