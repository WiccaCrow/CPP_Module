#include "Point.hpp"

float   point_pos_relative_line_one(const Point &a, const Point &b, const Point &p);
int     point_pos_relative_line_both(const Point &a, const Point &b, const Point &c, const Point &point);

bool    bsp( Point const a, Point const b, Point const c, Point const point)
{

    int ab = point_pos_relative_line_both(a, b, c, point);
    int bc = point_pos_relative_line_both(b, c, a, point);
    int cd = point_pos_relative_line_both(c, a, b, point);

// std::cout << (ab + bc + cd) << std::endl;
    if (3 == (ab + bc + cd))
        return (true);
    return (false); 
}

// Calculates the position of both points relative to line.
int point_pos_relative_line_both(const Point &a, const Point &b, const Point &c, const Point &point)
{
    float abc = point_pos_relative_line_one(a, b, c);
    float abp = point_pos_relative_line_one(a, b, point);
    // return (abc * abp >= 0);
    return (abc * abp > 0);

}

// Calculates the position of point relative to line ab.
// Any one point relative to any one straight line
float point_pos_relative_line_one(const Point &a, const Point &b, const Point &p)
{
    return (p.GetX() - a.GetX()) * (b.GetY() - a.GetY()) -
           (p.GetY() - a.GetY()) * (b.GetX() - a.GetX());
}

