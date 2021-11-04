#include "ClassPhonebook.hpp"

void	Phonebook::add()
{
	index = i_add + 1;
	ph_book[i_add].add();
	++i_add;
	if (i_add > 7)
		i_add = 0;
}

void	Phonebook::search()
{
	std::cout << "SEARCH\n";
	for (int i = 0; i < 8; ++i)
		if (index)
			ph_book[i].show();

	// std::cout << "first_name: " << first_name << std::endl;
	// std::cout << "last_name: " << last_name << std::endl;
	// std::cout << "nickname: " << nickname << std::endl;
	// std::cout << "phone_number: " << phone_number << std::endl;
	// std::cout << "darkest_secret: "<< darkest_secret << std::endl;
}