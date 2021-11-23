#include "main.hpp"

/*******************************************************************/
/*           3. replace_in_file                                    */
/*******************************************************************/
/* Description:
 * 		Read line from fin, replace s1 to s2, write to FILENAME.replace.
 * Contains functions:
 * 		3.1. replace_and_write;
*/

void	replace_in_file(char** &av, std::ifstream &fin)
{
/* Open FILENAME.replace to write */
    std::ofstream fout("FILENAME.replace", std::ios_base::out |
                                           std::ios_base::trunc);
    if (!fout.is_open())
    {
        std::cerr << ERROR_FILE_REPLACE_OPEN << std::endl;
        return ;
    }
    replace_and_write(fin, fout, av);
    fout.close();
}

/*******************************************************************/
/*           3.1. replace_and_write                                */
/*******************************************************************/
/* Description:
 * 		The function read line from fin, replace s1 to s2, write 
 *      to FILENAME.replace
 * Contains functions:
 * 		3.1.1.  replace_one_string;
*/

void	replace_and_write(std::ifstream &fin, std::ofstream &fout, char** &av)
{
    std::string	fin_str;

    while (!fin.eof())
    {
        getline(fin, fin_str);
        fout << replace_one_string(fin_str, av[2], av[3]);
        if (!fin.eof())
            fout << std::endl;
    }
}

/********************************************************************/
/*           3.1.1. replace_one_string                              */
/********************************************************************/
/* Description:
 * 		Replace s1 to s2 in str_replace
 * Return value:
 * 		std::string	&       to str_replace.
*/

std::string	&replace_one_string(std::string	&str_replace, char* &s1, char* &s2)
{
    size_t		s1_len = std::strlen(s1);

    for (size_t pos = str_replace.find(s1, 0);
        pos != std::string::npos;
        pos = str_replace.find(s1, pos))
    {
        str_replace.erase(pos, s1_len);
        str_replace.insert(pos, s2);
    }
    return (str_replace);
}
