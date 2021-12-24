#include "span.hpp"

/******************************************************************************/
/* Constructors */

//      init

Span::Span(const unsigned int N) : _N_max (N)
{ }

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

int  & Span::operator[](int i)
{
    return (_arr.at(i));
}


/******************************************************************************/
/* Private functions */

/******************************************************************************/
/* Public functions */

        /* Set atributs */

void    Span::addNumber(const int & nb)
{
    if (_arr.size() == static_cast<unsigned int>(_N_max))
        throw SpanException();
    _arr.push_back(nb);
}

void    Span::addNumber(const vect_iter & first, vect_iter last)
{
    if (_arr.size() == static_cast<unsigned int>(_N_max))
        throw SpanException();
    
    int dist = std::distance(first, last);
    int can_add = _N_max - _arr.size();

    if (dist > can_add)
        last += can_add;
    _arr.insert(_arr.end(), first, last);
    if (dist > can_add)
        throw SpanException();
}

        /* Get and show atributs */

        /* other methods */

int Span::shortestSpan()
{
    if (_arr.size() < 2)
        throw SpanException("    < Exception > : too few numbers.");
    std::vector<int> copy_arr = _arr;
    std::sort(copy_arr.begin(), copy_arr.end());
    unsigned int min = _arr[1] - _arr[0];
    for (unsigned int i_left = _arr.size(), i = 2, span; i < i_left; ++i)
    {
        span = _arr[i] - _arr[i - 1];
        min = std::min(min, span);
        if (!min)
            return (0);
    }
    return (min);
}

int Span::longestSpan()
{
    if (_arr.size() < 2)
        throw SpanException("    < Exception > : too few numbers.");
    vect_iter min = std::min_element(_arr.begin(), _arr.end());
    vect_iter max = std::max_element(_arr.begin(), _arr.end());
    return (*max - *min);
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