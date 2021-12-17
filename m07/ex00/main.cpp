#include "whatever.hpp"
#include "Fixed.hpp"

/*********************/
/*   4.1. test_color */
/*********************/
/* Description:
 *      Color output.
*/

void    test_color(const std::string text)
{
    std::cout << std::endl << "\033[36m" << text << "\033[0m";
}

/*********************/
/*   4. test         */
/*********************/
/* Description:
 *      test with my class.
 * Contains functions:
 *      4.1. test_color;
*/

void    test ()
{
    std::cout << "\n\x1b[30;42m" << "TEST" << "\x1b[0m" << std::endl;

    test_color ("Fixed fix_a = 5;\nFixed fix_b = 12;\n::swap(fix_a, fix_b);\n");
    Fixed a = 5;
    Fixed b = 12;

    ::swap(a, b);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    test_color("a = b");
    a = b;
    test_color("Fixed *ptr = &min( a, b );\n");
    Fixed *ptr = &min( a, b );
    std:: cout << "ptr: " << ptr << std::endl;
    std:: cout << "&b:  " << &b << std::endl;

    test_color("ptr = &max( a, b );\n");
    ptr = &max( a, b );
    std:: cout << "ptr: " << ptr << std::endl;
    std:: cout << "&b:  " << &b << std::endl;
}

/************/
/*  main    */
/************/
/* Description:
 *      Run prog.
 *
 * contains functions:
 *       1. swap;
 *       2. min;
 *       3. max;
 *       4. test;
*/

int main( void ) 
{
    int a = 2;
    int b = 3;

    ::swap( a, b );

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);

    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    test();
    
    return 0;
}