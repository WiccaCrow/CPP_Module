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
 *       5. test_check_list;
*/

void    test_check_list(void);

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

    test_check_list();
    
    return 0;
}


/******************************************************************************/
/*                             test_check_list                                */
/******************************************************************************/

class Awesome 
{ 
    public: 
        Awesome(void) : _n(0) {} 
        Awesome(int n):_n(n){} 
        Awesome& operator=(Awesome & a) { _n=a._n; return*this; } 

        bool operator==(Awesome const & rhs) const { return(this->_n==rhs._n); } 
        bool operator!=(Awesome const & rhs) const { return(this->_n!=rhs._n); } 
        bool operator>(Awesome const & rhs) const { return(this->_n>rhs._n); } 
        bool operator<(Awesome const & rhs) const { return(this->_n<rhs._n); } 
        bool operator>=(Awesome const & rhs) const { return(this->_n>=rhs._n); } 
        bool operator<=(Awesome const & rhs) const { return(this->_n<=rhs._n); } 
        
        int get_n() const { return _n; } 
        
    private: 
        int _n; 
}; 

std::ostream & operator<<(std::ostream & o,const Awesome & a) { o << a.get_n() ; return o ; }

void    test_check_list(void)
{
    std::cout << "\n\x1b[30;42m" << "TEST CHECK LIST" << "\x1b[0m" << std::endl;

    Awesome a(2), b(4);
    swap(a, b);
    std::cout << a << " " << b << std::endl; 
    std::cout << max(a,b) << std::endl; 
    std::cout << min(a,b) << std::endl; 
}