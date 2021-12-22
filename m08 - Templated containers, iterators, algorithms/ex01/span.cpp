#include "span.hpp"

/******************************************************************************/
/* Constructors */

//      init

Span::Span(const unsigned int N) : _N_max (N)
{
        // _arr.push_back(2);
}

//      copy

Span::Span(const Span & obj)
{
        operator=(obj);
}

/******************************************************************************/
/* Destructors */

Span::~Span()
{ }

/******************************************************************************/
/* Operators */

//      =

Span &  Span::operator=(const Span &obj)
{
        if (this != &obj)
        {
            _arr = obj._arr;
            _N_max = obj._N_max;
        }
        return (*this);
}

int  Span::operator[](int i) const
{
    return (_arr.at(i));
}


/******************************************************************************/
/* Private functions */

/******************************************************************************/
/* Public functions */

        /* Set atributs */

void    Span::addNumber(int nb)
{
        if (_arr.size() == static_cast<unsigned int>(_N_max))
                throw SpanException();
        _arr.push_back(nb);
}

        /* Get and show atributs */

        /* other methods */

// int Span::shortestSpan()
// {

// }

int Span::longestSpan()
{
    if (_arr.size() < 2)
        throw SpanException("    < Exception > : too few numbers.");
    std::pair<vect_iter,vect_iter> minmax_pair;
    minmax_pair = std::minmax_element(_arr.begin(), _arr.end());
    int minmax = *(minmax_pair.first) - *(minmax_pair.second);
    return (minmax < 0 ? -minmax : minmax);
}

/******************************************************************************/
/******************************************************************************/
        /* EXCEPTION */ /*SpanException*/


/******************************************************************************/
/* Constructors */

//      init

Span::SpanException::
            SpanException(const std::string message) :
                                          _message (message)
{ }

Span::SpanException::
            ~SpanException()  throw()
{ }

const char * Span::SpanException::
            what() const throw()
{
        return _message.c_str();
}