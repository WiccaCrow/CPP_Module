#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:

	    int fix_point;
	    static const int fractional_bits;

    public:
        Fixed(void);
        Fixed(int init_fix_point);
        Fixed(float init_fix_point);
        ~Fixed(void);
        Fixed(const Fixed &original_object);

        Fixed &     operator=(const Fixed &original_object);
        Fixed       operator*(const Fixed &object);
        Fixed       operator/(const Fixed &object);
        Fixed       operator-(const Fixed &object);
        Fixed       operator+(const Fixed &object);
        int         operator>(const Fixed &object);
        int         operator<(const Fixed &object);
        int         operator>=(const Fixed &object);
        int         operator<=(const Fixed &object);
        int         operator==(const Fixed &object);
        int         operator!=(const Fixed &object);

        Fixed &     operator++( void );
        Fixed       operator++( int );
        Fixed &     operator--( void );
        Fixed       operator--( int );

        static Fixed &          max( Fixed &a, Fixed &b );
        static const Fixed &    max( const Fixed &a, const Fixed &b );
        static Fixed &          min( Fixed &a, Fixed &b );
        static const Fixed &    min( const Fixed &a, const Fixed &b );

	    int         getRawBits (void) const; 
        void        setRawBits (int const raw);
        void        setRawBits (float const raw);
        float       toFloat(void) const;
        int         toInt(void) const;
};

std::ostream &  operator<<(std::ostream &os, const Fixed &object);

#endif
