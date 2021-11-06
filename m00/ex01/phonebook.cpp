#include "phonebook.hpp"

/************************************
 *              main                *
 * **********************************
*/
/* Includes functions:
 * 		1. phonebook_hello;
 *		2. parser
*/

int	main(void)
{
	phonebook_hello();
	parser();
	std::cout << EXIT_COM << std::endl;
	return (0);
}

/************************************
 *       1. phonebook_hello         *
 * **********************************
*/
/* Description:
 *		The function displays a greeting when starting 
 *		the phone book, available commands, their 
 *		description.
*/

void	phonebook_hello(void)
{
	std::cout << HELLO << std::endl;
	std::cout << COMMANDS << std::endl;
	std::cout << HELP << std::endl << std::endl;
}

/************************************
 *           2. parser              *
 * **********************************
*/
/* Description:
 *		The function reads a command from standard input 
 *		and calls functions to execute the entered command.
 * Includes functions:
 * 		2.1. get_command;
 *		ClassPhonebook.hpp: add(index);
 *		ClassPhonebook.hpp: search();
*/

void	parser(void)
{
	std::string command;
	Phonebook	ph_book;
	int			index = 0;

	while (command != EXIT_COM)
	{
		command = get_command();
		if (command == ADD)
		{
			ph_book.add(index);
			++index;
			if (index > 7)
				index = 0;
		}
		else if (command == SEARCH)
			ph_book.search();
	}
}

/************************************
 *        2.1. get_command          *
 * **********************************
*/
/* Description:
 *		The function displays the prompt you entered the command.
 *		And reads the entered string. If the command is entered 
 *		incorrectly, the function will ask you to enter the 
 *		command again.
 * Return value:
 * 		A string with a command in the format std::string.
*/

std::string	get_command(void)
{
	std::string	input;

	while (1)
	{
		std::cout << INPUT_INVITATION;
		getline(std::cin, input);
		if (input == ADD || input == SEARCH || input == EXIT_COM)
			break ;
	}
	return (input);
}