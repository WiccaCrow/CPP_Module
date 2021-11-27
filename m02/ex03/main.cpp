#include <iostream>
#include "Fixed.hpp"

void     my_tests(void);
void     my_tests_min(Fixed &a, const Fixed &b);

int  main( void ) { 

     Fixed   a;
     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

     std::cout << a << std::endl;
     std::cout << ++a << std::endl;
     std::cout << a << std::endl;
     std::cout << a++ << std::endl;
     std::cout << a << std::endl;

     std::cout << b << std::endl;

     std::cout << Fixed::max( a, b ) << std::endl;

     my_tests_min(a, b);
     my_tests();

     return 0; 
}

void     my_tests_min(Fixed &a, const Fixed &b)
{
     std::cout << "a is " << a << ", b is " << b << ", min is " << Fixed::min( a, b ) << std::endl;
}

void     my_tests(void)
{
     // operators + - /

     std::cout << std::endl << "+ - /" << std::endl;

     std::cout << "Fixed( 5.0f ) + Fixed( 2 ) result " << ( Fixed( 5.0f ) + Fixed( 2 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) - Fixed( 2 ) result " << ( Fixed( 5.0f ) - Fixed( 2 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) / Fixed( 2 ) result " << ( Fixed( 5.0f ) / Fixed( 2 ) ) << std::endl;

     // operators < > <= >= == !=

     std::cout << std::endl << "TRUE" << std::endl;

     std::cout << "Fixed( 5.0f ) > Fixed( 2 ) result " << ( Fixed( 5.0f ) > Fixed( 2 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) < Fixed( 20 ) result " << ( Fixed( 5.0f ) < Fixed( 20 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) >= Fixed( 2 ) result " << ( Fixed( 5.0f ) >= Fixed( 2 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) <= Fixed( 20 ) result " << ( Fixed( 5.0f ) <= Fixed( 20 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) == Fixed( 5 ) result " << ( Fixed( 5.0f ) == Fixed( 5 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) != Fixed( 20 ) result " << ( Fixed( 5.0f ) != Fixed( 20 ) ) << std::endl;

     std::cout << std::endl;

     std::cout << "Fixed( 5.0f ) >= Fixed( 5.0f ) result " << ( Fixed( 5.0f ) >= Fixed( 5.0f ) ) << std::endl;
     std::cout << "Fixed( 20.0f ) <= Fixed( 20 ) result " << ( Fixed( 20.0f ) <= Fixed( 20 ) ) << std::endl;

     std::cout << std::endl << "FALSE" << std::endl;

     std::cout << "Fixed( 5.0f ) > Fixed( 20 ) result " << ( Fixed( 5.0f ) > Fixed( 20 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) < Fixed( 2 ) result " << ( Fixed( 5.0f ) < Fixed( 2 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) >= Fixed( 20 ) result " << ( Fixed( 5.0f ) >= Fixed( 20 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) <= Fixed( 2 ) result " << ( Fixed( 5.0f ) <= Fixed( 2 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) == Fixed( 20 ) result " << ( Fixed( 5.0f ) == Fixed( 20 ) ) << std::endl;
     std::cout << "Fixed( 5.0f ) != Fixed( 5 ) result " << ( Fixed( 5.0f ) != Fixed( 5 ) ) << std::endl;

     // operators -- ++ 

     std::cout << std::endl << "--" << std::endl;
     Fixed my_test(5.0f);
     std::cout << "my_test = " << my_test << std::endl;
     std::cout << "--my_test result " << --my_test << std::endl << std::endl;

     std::cout << "++my_test result " << ++my_test << std::endl;
     std::cout << "my_test result-- result " << my_test-- << std::endl;
     std::cout << "now my_test is " << my_test << std::endl;
}
