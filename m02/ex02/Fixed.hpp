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

        Fixed & operator=(const Fixed &original_object);

	    int     getRawBits (void) const; 
        void    setRawBits (int const raw);
        void    setRawBits (float const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &  operator<<(std::ostream &os, const Fixed &object);

#endif
