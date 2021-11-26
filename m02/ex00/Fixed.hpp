#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:

        // Целое число для хранения для хранения значения фиксированной точки.
	    int fix_point;

        // Статическое постоянное целое число для хранения количества дробных битов.
        // Эта константа всегда будет литеральной 8.
	    static const int fractional_bits;

    public:
        Fixed(int init_fix_point = 0);
        ~Fixed(void);
        Fixed(const Fixed &original_object);

        Fixed & operator=(const Fixed &original_object);

	    int     getRawBits (void) const; 
        void    setRawBits (int const raw);
};

#endif
