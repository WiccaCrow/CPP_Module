#include "Fixed.hpp"

/******************************************************************************/
/* Static members */

const int Fixed::fractional_bits = 8;

/******************************************************************************/
/* Constructors */

//      init

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    setRawBits(0);
}

Fixed::Fixed(int init_fix_point)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(init_fix_point);
}

Fixed::Fixed(float init_fix_point)
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits(init_fix_point);
}

//      copy

Fixed::Fixed(const Fixed &original_object)
{
    std::cout << "Copy constructor called" << std::endl;
    operator=(original_object);
}

/******************************************************************************/
/* Destructors */

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

Fixed & Fixed::operator=(const Fixed &original_object)
{
    std::cout << "Assignation operator called ";
    std::cout << std::endl;
    if (this == &original_object)
        return (*this);
    fix_point = original_object.getRawBits();
        return (*this);    
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

int     Fixed::getRawBits (void) const
{
    return (fix_point);
}

void    Fixed::setRawBits (int const raw)
{
// With this shift << , I say that now the right 8 bits are reserved for the fractional part.
    fix_point = raw << fractional_bits;
}

        /*******************************************************************/
        /*          my_roundf                                              */
        /*******************************************************************/
        /* Description:
        *      Rewrite of roundf function (cmath).
        */

static float   my_roundf(float nb_in)
{
    float nb = nb_in;

    if (nb < 0)
        nb *= -1;
    if (nb - (int)nb >= 0.5)
        nb = (int)nb + 1;
    if (nb_in < 0)
        return (-(int)nb);
    return ((int)nb);
}

void    Fixed::setRawBits (float const raw)
{
// With this shift << , I say that now the right 8 bits are reserved for the fractional part. Dec in bin
    fix_point = my_roundf(raw * (1 << fractional_bits));
// printf("\n%f vs my_roundf = %f \n", raw * (1 << fractional_bits), my_roundf(raw * (1 << fractional_bits)));
}

float   Fixed::toFloat(void) const
{
// bin in dec
    return ((float)fix_point / (float)(1 << fractional_bits));
}

int   Fixed::toInt(void) const
{
    return (toFloat());
}

/******************************************************************************/
/* Other functions */
/* NO CLASS */

//      <<

std::ostream &  operator<<(std::ostream &os, const Fixed &object)
{
    os << object.toFloat();
    return (os); 
}