#include "MateriaSource.hpp"

/******************************************************************************/
/* Constructors */

//      init
MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource:      constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        _Source[i] = 0;
}

//      copy

/******************************************************************************/
/* Destructors */

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource:       destructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
        if (_Source[i])
            delete _Source[i];
}

/******************************************************************************/
/* Operators */

//      =

MateriaSource &   MateriaSource::operator=(const MateriaSource &obj)
{
    std::cout << "MateriaSource:    Assignation operator called " << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (_Source[i])
                delete _Source[i];
            if (obj._Source[i])
                _Source[i] = obj._Source[i]->clone();
            else
                _Source[i] = 0;
        }
    }
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

        /* other methods */

void MateriaSource::learnMateria(AMateria* obj)
{
    for (int i = 0; i < 4; ++i)
    {
        if ( !_Source[i])
        {
            _Source[i] = obj->clone();
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_Source[i] && _Source[i]->getType() == type)
        {
            return (_Source[i]->clone());
        }
    }
    return (0);
}
