#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define COMMANDS "Available commands: ADD, SEARCH, EXIT."
# define HELP "\tEnter ADD to add a new contact.\n\tEnter SEARCH to search the phone book.\n\tEnter EXIT to exit the program. When you exit the program, all data will be lost forever."
# define HELLO "Hello. To use the phone book, enter the command:"
# define ADD "ADD"
# define SEARCH "SEARCH"
# define EXIT_COM "EXIT"
# define INPUT_INVITATION "Enter one of the commands (ADD, SEARCH, EXIT):\t"

# include "ClassPhonebook.hpp"

void	    phonebook_hello(void);
void	    parser(void);
// std::string	get_command(void);
bool	get_command(std::string &input);

#endif