#include "mutantstack.hpp"

/******************************************************************************/
/* Constructors */

//      init

template<
    class T, 
    class Container 
        >
MutantStack<T, Container>::
MutantStack(void) : std::stack<T, Container>()
{ }

//      copy

template<
    class T, 
    class Container 
        >
MutantStack<T, Container>::
MutantStack(const MutantStack & obj) : std::stack<T, Container>(obj)
{ }

/******************************************************************************/
/* Destructors */

template<
    class T, 
    class Container 
        >
MutantStack<T, Container>::
~MutantStack()
{ }

/******************************************************************************/
/* Operators */

//      =

template<
    class T, 
    class Container 
        >
MutantStack<T, Container> &
MutantStack<T, Container>::operator=(const MutantStack &obj)
{
    if (this != &obj)
    {
        std::stack<T, Container>::operator=(obj);
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

template<
    class T, 
    class Container 
        >
typename MutantStack<T, Container>::iterator 
MutantStack<T, Container>::begin()
{
    return  (c.begin());
}

template<
    class T, 
    class Container 
        >
typename MutantStack<T, Container>::iterator 
MutantStack<T, Container>::end()
{
    return  (c.end());
}
