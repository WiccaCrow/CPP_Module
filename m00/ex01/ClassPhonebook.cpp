#include "ClassPhonebook.hpp"

int			ft_isdigit(const char &c);
std::string	get_add_number(void);

void	Phonebook::add()
{
	std::cout << ADD_START << std::endl;
	std::cout << ADD_NAME_1ST;
	getline(std::cin, first_name);
	std::cout << ADD_NAME_LAST;
	getline(std::cin, last_name);
	std::cout << ADD_NAME_NICK;
	getline(std::cin, nickname);
	std::cin >> nickname;
	phone_number = get_add_number();
	std::cin >> phone_number;
	std::cout << ADD_SECRET;
	getline(std::cin, darkest_secret);
	std::cin >> darkest_secret;
}

std::string	get_add_number(void)
{
	std::string	phone_number;

	std::cout << ADD_NUMBER_PHONE;
	getline(std::cin, phone_number);
	// for (int i = 0; phone_number[i]; ++i)
	// {
	// 	if (ft_isdigit(phone_number[i]))
	// 		continue ;
		




	// }

	return ();
}

int	ft_isdigit(const char &c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	Phonebook::search()
{}