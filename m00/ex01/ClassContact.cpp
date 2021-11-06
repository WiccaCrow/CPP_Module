#include "ClassContact.hpp"

void	    add_string(const char info[], std::string &get_string);
std::string	get_add_number(int &correct);
int			ft_isdigit(const char &c);
int			is_hyphen(std::string &phone_number, int &i);
void	print_string_10_char(const std::string &to_print, char c = '\n');
void	print_string(const std::string &to_print, char c);
void	print_string(const std::string &to_print);

void	Contact::add()
{
	int	correct = 0;

	std::cout << ADD_START << std::endl;
	add_string(ADD_NAME_1ST, first_name);
	add_string(ADD_NAME_LAST, last_name);
	add_string(ADD_NAME_NICK, nickname);
	while (!correct || phone_number[0] == 0)
		phone_number = get_add_number(correct);
	add_string(ADD_SECRET, darkest_secret);
}

void	add_string(const char info[], std::string &get_string)
{
	if (get_string[0])
		get_string = "";
	while (!get_string[0])
	{
		std::cout << info;
		getline(std::cin, get_string);
	}
}

std::string	get_add_number(int &correct)
{
	std::string	phone_number;
	int			bracket = 0;

	correct = 1;
	std::cout << ADD_NUMBER_PHONE;
	getline(std::cin, phone_number);
	for (int i = 0; phone_number[i]; ++i)
	{
		if (i == 0 && phone_number[0] == '+' && ft_isdigit(phone_number[1]))
			++i;
		else if (ft_isdigit(phone_number[i]) || is_hyphen(phone_number, i))
			continue ;
		else if ((!bracket && phone_number[i] == '(') || (bracket == 1 && phone_number[i] == ')' && phone_number[i - 1] != '('))
			++bracket;
		else
		{
			std::cout << ADD_NUMBER_PHONE_ERROR << std::endl;
			correct = 0;
			break ;
		}
	}
	return (phone_number);
}

int	ft_isdigit(const char &c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_hyphen(std::string &phone_number, int &i)
{
	if (phone_number[i] == '-' && i > 0
		&& ft_isdigit(phone_number[i - 1])
		&& ft_isdigit(phone_number[i + 1]))
		return (1);
	return (0);
}

void	Contact::show_contacts_all_name(int index)
{
	if (!first_name[0])
		return ;
	std::cout << std::setw(10) << index;
	std::cout << '|';
	print_string_10_char(first_name, '|');
	print_string_10_char(last_name, '|');
	print_string_10_char(nickname);
}

void	print_string_10_char(const std::string &to_print, char c) 
{
	int	len = 0;

	while (to_print[len])
		++len;
	if (len > 10)
	{
		for (int i = 0; i < 9; ++i)
			std::cout << to_print[i];
		std::cout << '.';
		std::cout << c;
	}
	else
		print_string(to_print, c);
}

int	Contact::show_contact_by_index(int index)
{
	if (!first_name[0])
	{
		if (index)
			std::cout << "The contact with index " << index << " is empty. Try SEARCH again." << std::endl;
		return (1);
	}
	else
	{
		if (0 == index)
			return (0);
		std::cout << "The contact with index " << index << ":" << std::endl;
		print_string(first_name);
		print_string(last_name);
		print_string(nickname);
		print_string(phone_number);
		print_string(darkest_secret);
	}
	return (0);
}

void	print_string(const std::string &to_print, char c) 
{
	std::cout << std::setw(10) << to_print;
	std::cout << c;
}

void	print_string(const std::string &to_print) 
{
	std::cout << to_print << std::endl;
}