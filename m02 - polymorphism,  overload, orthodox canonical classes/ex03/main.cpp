#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void      test_class_point_1(void);
void      test_class_point_2(Point const a, Point const b, Point const c, Point const point);
void      test_2_print(std::string text_head, std::string some_text,const Point &a, const Point &b, const Point &c, const Point &point);
bool      bsp( Point const a, Point const b, Point const c, Point const point);

int  main( void )
{ 
     float a_x = 2; float a_y = 3;
     float b_x = 6; float b_y = 7;
     float c_x = 9; float c_y = 2;
     // float point_x = 5; float point_y = 4;//yes
     // float point_x = 0; float point_y = 4;
     // float point_x = 2; float point_y = 3;
     float point_x = 6; float point_y = 6;//yes

     bool yes_no = bsp( Point(a_x, a_y), Point(b_x, b_y), Point(c_x, c_y), Point(point_x, point_y));

     if (yes_no)
          std::cout << "The position of the point is inside the triangle." << std::endl;
     else
          std::cout << "The position of the point is not inside the triangle." << std::endl;
 
     std::cout << std::endl << "Tests for constructors:" << std::endl;
     test_class_point_1();
     std::cout << std::endl << "Tests for -= and copy:" << std::endl;
     test_class_point_2(Point(a_x, a_y), Point(b_x, b_y), Point(c_x, c_y), Point(point_x, point_y));

     return 0;
}

void test_class_point_1(void)
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

void test_class_point_2(Point const a, Point const b, Point const c, Point const point)
{
     test_2_print("Start points: \n", ":     ", a, b, c, point);

     Point a_new = Point (a.GetX(), a.GetY());
     Point b_new = Point (b.GetX(), b.GetY());
     Point c_new = Point (c.GetX(), c.GetY());
     Point p_new = Point (point.GetX(), point.GetY());
     test_2_print("Start points (Point point_new = Point (old.GetX(), old.GetY())  ): \n", "_new: ", a_new, b_new, c_new, p_new);

     a_new -= a;
     b_new -= a;
     c_new -= a;
     p_new -= a;
     test_2_print("\nNew points (operator-=      point -= a): \n", "_new: ", a_new, b_new, c_new, p_new);

}

void    test_2_print(std::string text_head, std::string some_text,const Point &a, const Point &b, const Point &c, const Point &point)
{
    std::cout << text_head;
    std::cout << "a" << some_text; a.PrintPrivate();
    std::cout << "b" << some_text; b.PrintPrivate();
    std::cout << "c" << some_text; c.PrintPrivate();
    std::cout << "p" << some_text; point.PrintPrivate();    
}
