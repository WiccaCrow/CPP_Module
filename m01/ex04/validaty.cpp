#include "main.hpp"

/*******************************************************************/
/*          1. check_validity_ac                                   */
/*******************************************************************/
/* Description:
 * 		The function check validity number of arguments.
 * Return value:
 * 		1 - not valid.
 *      0 - valid.
*/

int	check_validity_ac(int &ac)
{
    if (ac != 4)
    {
        std::cerr << ERROR_VALID_AC << std::endl;
        return (1);
    }
    return (0);
}

/*******************************************************************/
/*          2. check_validity_av                                   */
/*******************************************************************/
/* Description:
 * 		The function check validity number of arguments.
 * Return value:
 *      If valid 0. Else - not 0.
 * Contains functions:
 * 		2.1.  check_validity_av_file;
 *      2.2.  check_validity_av_empty_entry;
*/

int	check_validity_av(char** &av, std::ifstream &filename)
{
    int	valid = check_validity_av_file(filename) +
                check_validity_av_empty_entry(av);
    if (1 == valid)
        filename.close();
    return (valid);
}

/*******************************************************************/
/*           2.1. check_validity_av_file                           */
/*******************************************************************/
/* Description:
 * 		The function check validity file.
 * Return value:
 *      If the file opened 0. Else 2.
*/

int	check_validity_av_file(std::ifstream &fin)
{
    if (!fin.is_open())
    {
        std::cerr << ERROR_VALID_AV_FILE_OPEN << std::endl;
        return (2);
    }
    return (0);
}

/*******************************************************************/
/*           2.2. check_validity_av_empty_entry                    */
/*******************************************************************/
/* Description:
 * 		The function check empy entry.
 * Return value:
 *      If not empty 0. 
 *      If empty 1.
*/

int	check_validity_av_empty_entry(char** &av)
{
    if (!av[1][0] || !av[2][0] || !av[3][0])
    {
        std::cerr << ERROR_VALID_AV_EMPTY << std::endl;
        return (1);
    }
    return (0);
}
