#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

#include <iostream>

#include <limits>
#include <sstream>
#include <string>
#include <iomanip>

class ScalarConversion
{
    private:
        std::string _av;
        int     _av_type;
        int     _possible[4];
        char    _c;
        int     _i;
        float   _f;
        double  _d;
        void (ScalarConversion::*func_ptr[4])();

        void    parse_av();
        int     check_limits_int();
        int    show_spec_float();
        int    show_spec_double();

    public:
        /* Constructs and destructs*/
        ScalarConversion(std::string av = "");

        ScalarConversion(const ScalarConversion &);
        ~ScalarConversion();

        /* operators */
        ScalarConversion &  operator=(const ScalarConversion &);

        /* Set atributs */
        /* Get and show atributs */
        void    show_all();

        /* other methods */
        void    cast_int();
        void    cast_char();
        void    cast_float();
        void    cast_double();

        template <typename C>
        void conv_to_char(C a)
        {
            if (!(a >= 0 && a < 128))
                _possible[0] = 0;
            _c = static_cast<char>(a);
        }

        template <typename I>
        void conv_to_int(I a)
        {
            if (a < std::numeric_limits<int>::min() || a > std::numeric_limits<int>::max())
                _possible[3] = 0;
            _i = static_cast<int>(a);
        }
};

#endif
