#include "Point.hpp"

void    bsp_print_points(std::string text_head, std::string some_text, const Point &a, const Point &b, const Point &c, const Point &point);

bool    bsp( Point const a, Point const b, Point const c, Point const point)
{
    bsp_print_points("Start points: \n", ":     ", a, b, c, point);

    Point a_new = Point (a.GetX(), a.GetY());
    Point b_new = Point (b.GetX(), b.GetY());
    Point c_new = Point (c.GetX(), c.GetY());
    Point p_new = Point (point.GetX(), point.GetY());
    bsp_print_points("Start points: \n", "_new: ", a_new, b_new, c_new, p_new);

    a_new -= a;
    b_new -= a;
    c_new -= a;
    p_new -= a;
    bsp_print_points("\nNew points: \n", "_new: ", a_new, b_new, c_new, p_new);

    return (true);


    // return (false); 

}

void    bsp_print_points(std::string text_head, std::string some_text,const Point &a, const Point &b, const Point &c, const Point &point)
{
    std::cout << text_head;
    std::cout << "a" << some_text; a.PrintPrivate();
    std::cout << "b" << some_text; b.PrintPrivate();
    std::cout << "c" << some_text; c.PrintPrivate();
    std::cout << "p" << some_text; point.PrintPrivate();    
}
