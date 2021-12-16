#include "ScalarConversion.hpp"

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
    if (_av_type < 4 )
        (this->*(func_ptr[_av_type]))();

    show_all();
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

ScalarConversion &  ScalarConversion::operator=(const ScalarConversion &obj)
{
    if (this != &obj)
    {
        _av = obj._av;
        _av_type = obj._av_type;
        for (int i = 0; i < 4; ++i)
            _possible[i] = obj._possible[i];
        _c = obj._c;
        _i = obj._i;
        _f = obj._f;
        _d = obj._d;
    }
    return (*this);
}

/******************************************************************************/
/* Private functions */

void    ScalarConversion::parse_av()
{
    if (1 == _av.length() && !std::isdigit(_av[0]))
        _av_type = 0; // char
    else if (!_av.compare("-inff") || !_av.compare("+inff") || !_av.compare("nanf"))
        _av_type = 4; // float spec
    else if (!_av.compare("-inf") || !_av.compare("+inf") || !_av.compare("nan"))
        _av_type = 5; // double spec
    else if (_av[_av.length() - 1] == 'f')
        _av_type = 1; // float
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

int    ScalarConversion::check_limits_int()
{
    if ((_av[0] != '-' && _av.length() > 10) || (_av[0] == '-' && _av.length() > 11))
        _possible[3] = 0;
    if ((_av[0] != '-' && _av.length() == 10) || (_av[0] == '-' && _av.length() == 11))
    {

        unsigned int int_to_cmp;
        if (_av[0] == '-')
        {
            std::istringstream streamm(&_av[1]);
            streamm >> int_to_cmp;
        }
        else
        {
            std::istringstream streamm(_av);
            streamm >> int_to_cmp;
        }
        if ((_av[0] == '-' && int_to_cmp > 2147483648u) ||
            (_av[0] != '-' && int_to_cmp > 2147483647u))
            {
                for (int i = 0; i < 4; ++i)
                    _possible[i] = 0;
            }
    }
    return (_possible[3]);
}

/******************************************************************************/
/* Public functions */

        /* Set atributs */

        /* Get and show atributs */

int    ScalarConversion::show_spec_float()
{
    if (_av_type == 4)
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << _av << std::endl;
        std::string av_copy = _av;
        av_copy[_av.length() - 1] = '\0';
        std::cout << "double: " << av_copy << std::endl;
        return (1); 
    }
    return (0);
}

int    ScalarConversion::show_spec_double()
{
    if (_av_type == 5)
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << _av << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << _av << std::endl;   
        return (1); 
    }
    return (0);
}


void    ScalarConversion::show_all()
{
    // std::cout << _av_type << std ::endl;
    if (show_spec_float() || show_spec_double())
        return ;
    if (_possible[0] && _c > 32)
        std::cout << "char: " << _c << std::endl;
    else if (_possible[0] && _c <= 32)
        std::cout << "char: " << "Non displayable" << std::endl;
    else
        std::cout << "char: " << "impossible" << std::endl;
    if (_possible[3])
        std::cout << "int: " << _i << std::endl;
    else
        std::cout << "int: " << "impossible" << std::endl;
    if (_possible[1])
        std::cout << "float: " << std::fixed << std::setprecision(1) << _f << "f" << std::endl;
    else
        std::cout << "float: " << "impossible" << std::endl;
    if (_possible[2])
        std::cout << "double: " << std::fixed << std::setprecision(1) << _d << std::endl;
    else
        std::cout << "double: " << "impossible" << std::endl;
}

        /* other methods */

void    ScalarConversion::cast_int()
{
    if (!check_limits_int())
        return ;
    std::istringstream stream(_av);
    stream >> _i;
    conv_to_char(_i);
    _f = static_cast<float>(_i);
    _d = static_cast<double>(_i);
}

void    ScalarConversion::cast_char()
{
    _c = _av[0];
    _f = static_cast<float>(_c);
    _d = static_cast<double>(_c);
    _i = static_cast<int>(_c);
}

void    ScalarConversion::cast_float()
{
    // _f = stof(_av);
    _f = std::strtof(_av.c_str(), NULL);
    conv_to_char(_f);
    _d = static_cast<double>(_f);
    conv_to_int(_f);
}

void    ScalarConversion::cast_double()
{
    // _d = stod(_av);
    _d = std::strtod(_av.c_str(), NULL);
    conv_to_char(_d);
    _f = static_cast<float>(_d);
    conv_to_int(_d);
}
