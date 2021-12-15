#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

#include <iostream>

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
};

#endif
