#include <iostream>
#include "span.hpp"

int main()
{
    Span sp = Span(5);

    try
    {
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11); // extra number is an exception.
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        for (int i = 0; i < 5; ++i)
            std::cout << sp[i] << std::endl;
            sp[-1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        Span sp;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}