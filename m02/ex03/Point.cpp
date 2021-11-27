#include "Point.hpp"

/******************************************************************************/
/* Constructors */

//      init

Point::Point(const float x_in, const float y_in, const int non_const_in) :
                x (x_in), y (y_in), non_const (non_const_in)
{ }

Point::Point(const int x_in, const int y_in, const int non_const_in) :
                x (x_in), y (y_in), non_const (non_const_in)
{ }

Point::Point(const Fixed x_in, const Fixed y_in, const int non_const_in) :
                x (x_in), y (y_in), non_const (non_const_in)
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
    non_const = original_object.non_const;
    return (*this);
}

float   Point::GetX(void) const
{
    return (x.toFloat());
}

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
    // std::cout << "Point:";
    PrintXY();
    std::cout << " , non_const is " << non_const  << std::endl;
}

