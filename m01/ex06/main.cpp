#include "Karen.hpp"

/*******************************************************************/
/*          1. check_valid_ac                                      */
/*******************************************************************/
/* Description:
 *      The function ac validity.
*/

int check_valid_ac(int ac)
{
    if (ac == 2)
        return (0);
    std::cout << ERROR_AC_NB << std::endl;
    return (1);
}

/*******************************************************************/
/*          0. main                                                */
/*******************************************************************/
/* Contains functions:
 *      1. check_valid_ac;
*/

int main( int ac, char **av )
{
    Karen   k_2_0;

    if (check_valid_ac(ac))
        return (1);
    k_2_0.complain(av[1]);
    return (0);
}

