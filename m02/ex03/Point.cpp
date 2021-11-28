#include "Point.hpp"

/******************************************************************************/
/* Constructors */

//      init

Point::Point(const float x_in, const float y_in) :
                x (x_in),               y (y_in),
            x_new (x_in),           y_new (y_in)
{ }

Point::Point(const int x_in, const int y_in) :
                x (x_in),           y (y_in),
            x_new (x_in),           y_new (y_in)
{ }

Point::Point(const Fixed x_in, const Fixed y_in) :
                x (x_in),               y (y_in),
            x_new (x_in),           y_new (y_in)
{ }

//      copy

Point::Point(const Point &original_object)
{
    operator=( original_object);
}

/******************************************************************************/
/* Destructors */

Point::~Point() 
{ }

/******************************************************************************/
/* Operators */

//      =

Point & Point::operator=(const Point &original_object)
{
    // std::cout << "Assignation operator called ";
    // std::cout << std::endl;
    if (this == &original_object)
        return (*this);
    x_new = original_object.x_new;
    y_new = original_object.y_new;
    return (*this);
}

Point   Point::operator-(const Point &object) const
{
    Point temp = Point(x_new - object.x_new, y_new - object.y_new);
    return temp;
}

Point &   Point::operator-=(const Point &object)
{
    Point temp = operator-(object);
    return (*this = temp);
}

Point   Point::operator+(const Point &object)
{
    Point temp = Point(x_new + object.x_new, y_new + object.y_new);
    return temp;
}

float   Point::GetX(void) const
{
    return (x.toFloat());
}

/******************************************************************************/
/* Functions */

float   Point::GetY(void) const
{
    return (y.toFloat());
}

void    Point::PrintXY(void) const
{
    std::cout.setf(std::ios::left);
    std::cout.width(10);
    std::cout << " x is ";
    std::cout.width(10);
    std::cout << GetX() << " , y is ";
    std::cout.width(10);
    std::cout  << GetY();
    std::cout.unsetf(std::ios::left);
}

void    Point::PrintPrivate(void) const
{
    PrintXY();
    std::cout.setf(std::ios::left);
    std::cout << " , x_new is ";
    std::cout.width(10);
    std::cout << x_new << " , y_new is " << y_new << std::endl;
    std::cout.unsetf(std::ios::left);
}

