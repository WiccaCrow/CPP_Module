#include "ClassPhonebook.hpp"

void	print_table_cap(void);
void	print_string(std::string string, char c);
int		take_index(void);

// Phonebook::Phonebook()
// {
// 	i_add = 0;
// }

// Phonebook::~Phonebook()
// {
// }

void	Phonebook::add(int index)
{
	contact[index].add();
}

void	Phonebook::search()
{
	int	index;

	print_table_cap();
	// if (1 == contact[0].show_contacts_all_name(1))
	// 	return ;
	for (int i = 0; i < 8; ++i)
		contact[i].show_contacts_all_name(i + 1);
	if (contact[0].show_contact_by_index(0))
		return ;
	index = take_index();
	contact[index - 1].show_contact_by_index(index);
}

int	take_index()
{
	std::string	input;

	std::cout << "Enter the index of the desired entry (without spaces or tabs):\t" << std::endl;
	while (1)
	{
		getline(std::cin, input);
		if (!input[0])
			std::cout << "Empty entry." << std::endl << "Index must be from 1 to 8. Try again." << std::endl;
		else if (input[1] || (!input[1] && (input[0] - '0' < 1 || input[0] - '0' > 8)))
		{
if (input[1])
std::cout << "input 1" << std::endl;
else if (input[0] - '0' < 1 || input[0] - '0' > 8)
std::cout << "input 1 no, wrong diapasone" << std::endl;


			std::cout << "Index must be a number from 1 to 8. Try again." << std::endl;
		}
		else
			break ;
	}
	return (input[0] - '0');
}

void	print_table_cap(void)
{
	print_string("index", '|');
	print_string("first name", '|');
	print_string("last name", '|');
	print_string("nickname", '\n');

}

void	print_string(std::string string, char c)
{
	std::cout << std::setw(10) << string;
	std::cout << c;
}