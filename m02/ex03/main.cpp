#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void test_class_point(void);
bool bsp( Point const a, Point const b, Point const c, Point const point);

int  main( void )
{ 
     float a_x = 2; float a_y = 3;
     float b_x = 6; float b_y = 7;
     float c_x = 9; float c_y = 2;
     float point_x = 5; float point_y = 4;

     bsp( Point(a_x, a_y), Point(b_x, b_y), Point(c_x, c_y), Point(point_x, point_y));

// test_class_point();

     return 0; 
}

void test_class_point(void)
{
std::cout << "Point xy_default; \n\t\t\t\t\t";
     Point xy_default;
     xy_default.PrintPrivate();

std::cout << "Point xy_init_int = Point(2, 1); \n\t\t\t\t\t";
     Point xy_init_int = Point(2, 1);
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

