#include "phonebook.hpp"

int	main(void)
{
	phonebook_hello();
	parser();
	std::cout << EXIT_COM << std::endl;
	return (0);
}

void	phonebook_hello(void)
{
	std::cout << HELLO << std::endl;
	std::cout << COMMANDS << std::endl;
	std::cout << HELP << std::endl << std::endl;
}

void	parser(void)
{
	std::string command;
	Phonebook	ph_book;
	while (command != EXIT_COM)
	{
		command = get_command();
		if (command == ADD)
			ph_book.add();
		else if (command == SEARCH)
			ph_book.search();
	}
}

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