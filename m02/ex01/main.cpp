#include <iostream>
#include "Fixed.hpp"

void  my_func(Fixed &a, const Fixed &b, const Fixed &c, const Fixed &d);

int    main( void ) {

       Fixed a;
       Fixed const b( 10 ); 
       Fixed const c( 42.42f ); 
       Fixed const d( b );

       a = Fixed( 1234.4321f );

       std::cout << "a is " << a << std::endl;
       std::cout << "b is " << b << std::endl;
       std::cout << "c is " << c << std::endl;
       std::cout << "d is " << d << std::endl;

       std::cout << "a is " << a.toInt() << " as integer" << std::endl;
       std::cout << "b is " << b.toInt() << " as integer" << std::endl;
       std::cout << "c is " << c.toInt() << " as integer" << std::endl;
       std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// my_func(a,b,c,d);
       return 0; 
}

void  my_func(Fixed &a, const Fixed &b, const Fixed &c, const Fixed &d)
{
   std::cout << "a.fix_point is " << a.getRawBits() << std::endl;
   std::cout << "b.fix_point is " << b.getRawBits() << std::endl;
   std::cout << "c.fix_point is " << c.getRawBits() << std::endl;
   std::cout << "d.fix_point is " << d.getRawBits() << std::endl;

   std::cout << "a.toFloat is " << a.toFloat() << std::endl;
   std::cout << "b.toFloat is " << b.toFloat() << std::endl;
   std::cout << "c.toFloat is " << c.toFloat() << std::endl;
   std::cout << "d.toFloat is " << d.toFloat() << std::endl;

printf("%f\n", c.toFloat());
}