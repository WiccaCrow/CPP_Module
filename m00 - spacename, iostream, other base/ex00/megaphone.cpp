#include <iostream>

/************************************
 *      1. print_uppercase          *
 * **********************************
*/
/* Description:
 *		The function change text to uppercase and 
 *		print result.
 * Includes functions:
 * 		1.1. ft_toupper;
*/

void    print_uppercase(int ac, char **av)
{
	for (int i_ac = 1; i_ac < ac; ++i_ac)
	{
		for (int i_av = 0; av[i_ac][i_av]; ++i_av)
			std::cout << (char) std::toupper(av[i_ac][i_av]);
	}
	std::cout << std::endl;
}

/************************************
 *              main                *
 * **********************************
*/
/* Includes functions:
 * 		1. print_uppercase;
*/

int main(int ac, char **av)
{
    if (ac > 1)
        print_uppercase(ac, av);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}