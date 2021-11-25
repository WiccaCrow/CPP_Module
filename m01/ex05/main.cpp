#include "Karen.hpp"

/*******************************************************************/
/*          0. main                                                */
/*******************************************************************/
/* Contains functions:
 * 		1. convert_complain;
*/
std::string &convert_complain(std::string &input);

int main( void )
{
    Karen   k_2_0;

    std::cout << INPUT_INVITATION << INPUT_HELP;
    for (std::string input; !std::cin.eof(); getline(std::cin, input))
    {
        if (!input[0])
            continue ;
        std::cout << std::endl;
        if (input == (std::string) "q" || input == (std::string) "Q" ||
            input == (std::string) "EXIT")
            break ;
        convert_complain(input);
        k_2_0.complain(input);
        std::cout << std::endl << INPUT_INVITATION << INPUT_HELP;
    }
    return (0);
}

/*******************************************************************/
/*          1. convert_complain                                    */
/*******************************************************************/
/* Description:
 *      The function converts the number of complain level to string
 *      with name of complain level.
*/

std::string &convert_complain(std::string &input)
{
    if ("1" == input)
        input = "DEBUG";
    if ("2" == input)
        input = "INFO";
    if ("3" == input)
        input = "WARNING";
    if ("4" == input)
        input = "ERROR";
    return (input);
}
