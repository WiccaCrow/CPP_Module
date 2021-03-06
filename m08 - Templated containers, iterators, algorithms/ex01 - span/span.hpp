#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
    private:
        typedef std::vector<int>::iterator vect_iter;
        std::vector<int>    _arr;
        vect_iter           _iter;
        int                 _N_max;

    public:
        /* Constructs and destructs*/
        Span(const unsigned int N = 0);
        Span(const Span & obj);
        ~Span();

        /* operators */
        Span &  operator=(const Span &obj);
        int  &  operator[](int i);

        /* Set atributs */
        void    addNumber(const int &nb);
        void    addNumber(const vect_iter & first, vect_iter last);

        /* Get and show atributs */
        
        /* other methods */
        int shortestSpan();
        int longestSpan();

        /* exception */
        class SpanException : public std::exception
        {
            private:
                const std::string _message;
            public:
                SpanException(const std::string message = "    < Exception > : Span error. All the cells for storing numbers are already occupied.");
                virtual ~SpanException() throw();
                virtual const char * what() const throw();
        };
};

#endif
