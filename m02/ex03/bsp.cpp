#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{

    Point a_new;
    a_new.PrintPrivate();

float x = b.GetX();
float y = b.GetY();

float xa = a.GetX();
float ya = a.GetY();

    // Point b_new = Point(x - xa, y - ya);
    // b_new.PrintPrivate();

b.PrintPrivate();
c.PrintPrivate();
point.PrintPrivate();
    return (true);


    // return (false);

}