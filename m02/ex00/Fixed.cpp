#include "Fixed.hpp"

/******************************************************************************/
/* Static members */

const int Fixed::fractional_bits = 8;

/******************************************************************************/
/* Constructors */

//      init

Fixed::Fixed(int init_fix_point)
    //   fix_point (init_fix_point)
{
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return (fix_point);
}

void    Fixed::setRawBits (int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    fix_point = raw;
}
