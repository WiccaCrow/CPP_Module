#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void test_class_point(void);
bool bsp( Point const a, Point const b, Point const c, Point const point);

int  main( void )
{ 
     Point a = Point(2, 3);
     Point b = Point(6, 7);
     Point c = Point(9, 2);
     Point point = Point(5, 4);

     bsp( a, b, c, point);

// test_class_point();

     return 0; 
}

void test_class_point(void)
{
std::cout << "Point xy_default; \n\t\t\t\t\t";
     Point xy_default;
     xy_default.PrintPrivate();

std::cout << "Point xy_init_int = Point(2, 1, 100); \n\t\t\t\t\t";
     Point xy_init_int = Point(2, 1, 100);
     xy_init_int.PrintPrivate();

std::cout << "Point xy_init_float = Point(2.2f, 1.1f); \n\t\t\t\t\t";

     Point xy_init_float = Point(2.2f, 1.1f);
     xy_init_float.PrintPrivate();

std::cout << "Point xy_init_Fixed = \nPoint(Fixed(2.2f) * 2, Fixed(1.1f)); \n\t\t\t\t\t";

     Point xy_init_Fixed = Point(Fixed(2.2f) * 2, Fixed(1.1f));
     xy_init_Fixed.PrintPrivate();

std::cout << "xy_default = xy_init_int; \n\t\t\t\t\t";
     xy_default = xy_init_int;
     xy_default.PrintPrivate();

std::cout << "Point xy_copy = xy_init_int; \n\t\t\t\t\t";
     Point xy_copy = xy_init_int;
     xy_copy.PrintPrivate();

}

