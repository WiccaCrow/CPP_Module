#include "ScalarConversion.hpp"

int    check_valid_av1(std::string av);

int main(int ac, char **av)
{
    if (ac == 2 && !check_valid_av1(av[1]))
    {
        ScalarConversion    tets(av[1]);
    }
    else
        std::cerr << "Error: wrong number of arguments or not valid entry (string to conversion)." << std::endl;
    return (0);
}

int    check_valid_av1(std::string av)
{
    if (!av.length())
        return (1);
    if (!av.compare("-inff") || !av.compare("+inff") || !av.compare("nanf") ||
        !av.compare("-inf")  || !av.compare("+inf")  || !av.compare("nan"))
        return (0);
    if (1 == av.length())
        return (0);
    int point, i = 0;
    if (av[0] == '-')
        ++i;
    if (!std::isdigit(av[i]))
        return (1);
    for (point = 0; av[i] && point < 2; ++i)
    {
        if (!std::isdigit(av[i]))
        {
            if (av[i] == '.')
                point += 1;
            else
                break ;
        }
        if (point > 1)
            return (1);
    }
    if ((av[i] == 'f' && 1 == point && !av[i + 1]) || !av[i])
        return (0);
    return (1);
}
