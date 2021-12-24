#include "span.hpp"
#include <iostream>
#include <sstream>

void    check_10000(int N_el, int max_el);
void    test_color_h1(const std::string text);
void    test_color_h2(const std::string text);
void    test_color_h3(const std::string text);

int main()
{
    test_color_h1(" main ");
    test_color_h2("create Span object (max 5 el), add numbers (6 element)");
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
        test_color_h3("An exception was thrown when trying to add an extra element: \n");
        std::cerr << e.what() << '\n';
    }
    
    test_color_h2("print 5 elements, try -1 element:");
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

    test_color_h2("shortestSpan, longestSpan");
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    test_color_h2("shortestSpan (empry Span), longestSpan (one element)");
    try
    {
        Span sp;
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Span sp(2);
        sp.addNumber(5);
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    check_10000(12000, 13000);

    return (0);
}

///////////////////////////////////////////////////////////////

/*********************/
/*     test_color_h */
/*********************/
/* Description:
 *      Color output.
*/

void    test_color_h3(const std::string text)
{
    std::cout << std::endl << "\033[36m" << text << "\033[0m";
}

void    test_color_h1(const std::string text = "test")
{
    std::cout << "\n\x1b[30;42m" << text << "\x1b[0m" << std::endl;
}

void    test_color_h2(const std::string text = "test")
{
    std::cout << "\033[92m" << "  _____________________________________" << std::endl;
    std::cout << "  ||  " << text << std::endl;
    std::cout << "  || \n  \\/ " << "\033[0m" << std::endl;
}


///////////////////////////////////////////////////////////////

/*********************/
/*     check_10000   */
/*********************/
/* Description:
 *      The function checks for any number of elements.
*/

void    check_10000(int N_el, int max_el)
{
    std::string N_el_str = static_cast<std::ostringstream*>( &(std::ostringstream() << N_el) )->str();
    std::string max_el_str = static_cast<std::ostringstream*>( &(std::ostringstream() << max_el) )->str();
 
    test_color_h1("check_10000");
    test_color_h2("create vector object (" + max_el_str + " el), fill it:");

    std::vector<int> numbers_12000(N_el);
    srand(time(NULL));
    for (int i = 0; i < N_el; i++)
    {
        const int value = rand();
        numbers_12000[i] = value;
    }

    test_color_h2("create Span object (max " + max_el_str + " el), add numbers from vector with " + N_el_str + " elements (with a range of iterators):");
    try
    {
        Span sp(max_el);
        sp.addNumber(numbers_12000.begin(), numbers_12000.end());
        test_color_h3("I check the correctness of the addition: sp_obj[i] == vect_obj[i]\n");
        for (int i = 0 ; i < N_el && i < max_el ; ++i)
        {
            if (sp[i] !=  numbers_12000[i])
                throw Span::SpanException("not equal");
        }
        std::cout << "equal" << std::endl;

        test_color_h2("Repeat adding:");
        sp.addNumber(numbers_12000.begin(), numbers_12000.end());
        std::cout << "You will never see it. " << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
