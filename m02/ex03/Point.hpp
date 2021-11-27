#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
        int   non_const;

        void    PrintXY(void) const;

    public:
    //      init
        Point(const float x_in = 0, const float y_in = 0, const int non_const_in = 0);
        Point(const int x_in, const int y_in, const int non_const_in = 0);
        Point(const Fixed x_in, const Fixed y_in, const int non_const_in = 0);
    //      copy
        Point(const Point &original_object);
        ~Point(void);
    //      operators
        Point &     operator=(const Point &original_object);

    //      functions
        float   GetX(void) const;
        float   GetY(void) const;
        void    PrintPrivate(void) const;


};

#endif