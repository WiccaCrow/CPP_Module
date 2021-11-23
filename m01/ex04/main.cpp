#include "main.hpp"

/*******************************************************************/
/*          0. main                                                */
/*******************************************************************/
/* Contains functions:
 * 		1. check_validity_ac;
 *      2. check_validity_av;
 *      3. replace_in_file;
*/

int main(int ac, char **av)
{
    if (check_validity_ac(ac))
        return (1);
    std::ifstream filename(av[1], std::ios_base::in);
    if (check_validity_av(av, filename))
        return (1);
    replace_in_file(av, filename);
    filename.close();
    return (0);
}
