#include "ClassPhonebook.hpp"

void	print_table_cap(void);
void	print_string(std::string string, char c);

// Phonebook::Phonebook()
// {
// 	i_add = 0;
// }

// Phonebook::~Phonebook()
// {
// }

void	Phonebook::add(int index)
{
// std::cout << "Phonebook::add " << index << std::endl;
	contact[index].add();
	// ++i_add;
	// if (i_add > 7)
	// 	i_add = 0;
}

void	Phonebook::search()
{
	print_table_cap();
	for (int i = 0; i < 8; ++i)
	{
		// std::cout << std::setw(10) << i + 1;
		// std::cout << '|';
		contact[i].show(i + 1);
	}
}

void	print_table_cap(void)
{
	std::string	p;
	
	p = "index";
	print_string(p, '|');
	p = "first name";
	print_string(p, '|');
	p = "last name";
	print_string(p, '|');
	p = "nickname";
	print_string(p, '\n');
}

void	print_string(std::string string, char c)
{
	std::cout << std::setw(10) << string;
	std::cout << c;
}