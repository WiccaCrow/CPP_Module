#include "ClassPhonebook.hpp"

/**********************************************
 *     class Phonebook:      1. add           *
 * ********************************************
*/
/* Description:
 *		The function adds a new contact at the specified index 
 *		(index should be from 0 to 7 - maximum 8 contacts).
 * Includes functions:
 *		ClassContact.hpp: add();
*/

void	Phonebook::add(int index)
{
	if (index >= 0 && index < 8)
		contact[index].add();
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/**********************************************
 *     class Phonebook:      2. search        *
 * ********************************************
*/
/* Description:
 *		The function will display a list of the available non-empty contacts 
 *		in 4 columns: index, first name, last name and nickname.
 *		Then the function will prompt again for the index of the desired entry 
 *		and displays the contact’s information, one field per line.
 * Includes functions:
 *		2.1. print_table_cap;
 *		2.2. take_index;
 *		ClassContact.hpp: show_contacts_all_name;
 *		ClassContact.hpp: show_contact_by_index;
*/

void	Phonebook::search()
{
	int	index;

	print_table_cap();
	for (int i = 0; i < 8; ++i)
		contact[i].show_contacts_all_name(i + 1);
	if (contact[0].show_contact_by_index(0))
		return ;
	index = take_index();
	contact[index - 1].show_contact_by_index(index);
}

/***************************************************
 *     class Phonebook:      2.1.  print_table_cap *
 * *************************************************
*/
/* Description:
 *		The function displays the header of the table with contacts.
 * Includes functions:
 *		2.1.1. print_string;
*/

void	Phonebook::print_table_cap(void)
{
	print_string("index", '|');
	print_string("first name", '|');
	print_string("last name", '|');
	print_string("nickname", '\n');

}

/***************************************************
 *     class Phonebook:      2.1.1.  print_string  *
 * *************************************************
*/
/* Description:
 *		The function displays string. Format: 10 chars wide.
*/

void	Phonebook::print_string(std::string string, char c)
{
	std::cout << std::setw(10) << string;
	std::cout << c;
}

/**********************************************
 *     class Phonebook:      2.2. take_index  *
 * ********************************************
*/
/* Description:
 *		The function prompts you to enter the contact's index in the phone 
 *		book until the correct index is entered.
*/

int	Phonebook::take_index()
{
	std::string	input;

	std::cout << INDEX_INPUT_INVITATION << std::endl;
	while (1)
	{
		getline(std::cin, input);
		if (!input[0])
			std::cout << INDEX_ERROR_EMPTY << std::endl 
					  << INDEX_ENTRY_HELP << std::endl;
		else if (input[1] 
			|| (!input[1] && (input[0] - '0' < 1 || input[0] - '0' > 8)))
			std::cout << INDEX_ENTRY_HELP << std::endl;
		else
			break ;
	}
	return (input[0] - '0');
}
