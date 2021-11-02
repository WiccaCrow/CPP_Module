#include<iostream>

#define NB_CONTACTS 8
#define COMMANDS "Available commands: ADD, SEARCH, EXIT."
#define HELP "\tEnter ADD to add a new contact.\n\tEnter SEARCH to search the phone book.\n\tEnter EXIT to exit the program. When you exit the program, all data will be lost forever."
#define HELLO "Hello. To use the phone book, enter the command:"
#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT_COM "EXIT"
#define INPUT_INVITATION "Enter one of the commands (ADD, SEARCH, EXIT):\t"

class Phonebook
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
};

void	phonebook_hello(void);
void	parser(void);

int	main(void)
{
	Phonebook	ph_book[NB_CONTACTS];

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
	std::string command ("");
	while (command != EXIT_COM)
	{
		std::cout << INPUT_INVITATION;
		std::cin >> command;
		if (command == ADD)
		{
			std::cout << "ADD\n";
		}
		else if (command == SEARCH)
		{
			std::cout << "SEARCH\n";
		}
	}
}