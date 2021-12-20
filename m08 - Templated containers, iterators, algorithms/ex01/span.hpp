#ifndef SPAN_HPP
# define SPAN_HPP

#include <array>
#include <iostream>

class Span
{
    private:

    public:
        /* Constructs and destructs*/
        Span(const unsigned int N = 0);
        Span(const Span & obj);
        ~Span();

        /* operators */
        Span &  operator=(const Span &obj);

        /* Set atributs */
        void    addNumber(int nb) const;

        /* Get and show atributs */
        /* other methods */
};

#endif
