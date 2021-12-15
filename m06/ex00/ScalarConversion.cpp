#include "ScalarConversion.hpp"

#include <sstream>
#include <iostream>
#include <string>

/******************************************************************************/
/* Constructors */

//      init
ScalarConversion::ScalarConversion(std::string av) :
        _av (av)
{
    for (int i = 0; i < 4; ++i)
        _possible[i] = 1;
    func_ptr[0] = &ScalarConversion::cast_char;
    func_ptr[1] = &ScalarConversion::cast_float;
    func_ptr[2] = &ScalarConversion::cast_double;
    func_ptr[3] = &ScalarConversion::cast_int;

    // The function fills _av_type
    parse_av();

    // calls casts and fills other variables
    // *func_ptr[_av_type];
    (this->*(func_ptr[_av_type]))();
    std::cout << "test 3\n";

    // for (int i = _av_type + 1; i != _av_type; ++i)
    // {
    //     if (i == 4)
    //         i = 0;
    //     // func_ptr[i];
    //     (this->*(func_ptr[_av_type]))();
    //     if (i == 3)
    //         i = -1;
    // }
    std::cout << "test 4\n";
}

//      copy

ScalarConversion::ScalarConversion(const ScalarConversion &obj)
{
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

ScalarConversion::~ScalarConversion()
{}

/******************************************************************************/
/* Operators */

//      =

ScalarConversion &  ScalarConversion::operator=(const ScalarConversion &)
{
    return (*this);
}

/******************************************************************************/
/* Private functions */

void    ScalarConversion::parse_av()
{
    if (1 == _av.length() && !std::isdigit(_av[0]))
        _av_type = 0; // char
    else if ((!_av.compare("-inff") || !_av.compare("+inff") || !_av.compare("nanf")) ||
                _av[_av.length() - 1] == 'f')
        _av_type = 1; // float
    else if (!_av.compare("-inf") || !_av.compare("+inf") || !_av.compare("nan"))
        _av_type = 2; // double
    else
    {
        int point, i = 0;  
        for (point = 0; _av[i] && !point; ++i)
            if (_av[i] == '.')
            {
                _av_type = 2; // double
                return ;
            }
        _av_type = 3; // int
    }
}


/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

void    ScalarConversion::show_all()
{
    if (_possible[0])
        std::cout << "char: " << _c << std::endl;
    if (_possible[3])
        std::cout << "int: " << _i << std::endl;
    if (_possible[1])
        std::cout << "float: " << _f << std::endl;
    if (_possible[2])
        std::cout << "double: " << _d << std::endl;
}

        /* other methods */

void    ScalarConversion::cast_int()
{
    std::istringstream stream(_av);
    stream >> _i;
    _c = static_cast<float>(_i);
    _f = static_cast<float>(_i);
    _d = static_cast<double>(_i);

    show_all();

}

void    ScalarConversion::cast_char()
{
    std::cout << "test 1\n";
    _c = _av[0];
    _f = static_cast<float>(_c);
    _d = static_cast<double>(_c);
    _i = static_cast<int>(_c);
    std::cout << "test 2\n";

    show_all();

}

void    ScalarConversion::cast_float()
{
    _f = stof(_av);
    _c = static_cast<float>(_f);
    _d = static_cast<double>(_f);
    _i = static_cast<int>(_f);

    show_all();

}

void    ScalarConversion::cast_double()
{
    _d = stod(_av);
    _c = static_cast<float>(_d);
    _f = static_cast<float>(_d);
    _i = static_cast<int>(_d);

    show_all();

}
