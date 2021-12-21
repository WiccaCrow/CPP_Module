#include "Span.hpp"

/******************************************************************************/
/* Constructors */

//      init

Span::Span(const unsigned int N) : _N_max (N)
{ }

//      copy

Span::Span(const Span & obj) : _N_max (obj._N_max)
{
        for (int i = 0 ; i < _N_max ; ++i)
                addNumber(obj._arr[i]);
}

/******************************************************************************/
/* Destructors */

Span::~Span()
{ }

/******************************************************************************/
/* Operators */

//      =

// Span &  Span::operator=(const Span &obj)
// {
//         if (this != &obj)
//         {
//                 for (int i = 0; i < _N_max && i < obj._N_max  && 
//                                 ; ++i)
//                         _arr[i] = obj._arr[i];
//         }
//         return (*this);
// }

/******************************************************************************/
/* Private functions */

/******************************************************************************/
/* Public functions */

        /* Set atributs */

void    Span::addNumber(int nb) const
{
        if (_arr.size() < _N_max)
        {}
        else
                throw 1;
}

        /* Get and show atributs */

        /* other methods */