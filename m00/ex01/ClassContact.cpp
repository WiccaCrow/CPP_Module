#include "ClassContact.hpp"

/**********************************************
 *     class Phonebook:      1. add           *
 * ********************************************
*/
/* Description:
 *		The function prompt the user to input a new contact’s information, one
 *		field at a time, until every field is accounted for.
 * Includes functions:
 * 		1.1. add_string;
 *		1.2. get_add_number;
*/

void	Contact::add()
{
	int	correct = 0;

	std::cout << ADD_START << std::endl;
	add_string(ADD_NAME_1ST, first_name);
	add_string(ADD_NAME_LAST, last_name);
	add_string(ADD_NAME_NICK, nickname);
	while (!std::cin.eof() && (!correct || phone_number[0] == 0))
		phone_number = get_add_number(correct);
	add_string(ADD_SECRET, darkest_secret);
}

/**********************************************
 *     class Phonebook:      1.1. add_string  *
 * ********************************************
*/
/* Description:
 *		The function add string datas. And check correct input.
 * Includes functions:
 * 		1.1.1. check_string_to_correct_simbols;
*/

void	Contact::add_string(const char info[], std::string &get_string)
{
	int	correct = 0;

	if (get_string[0])
		get_string = "";
	while (!std::cin.eof() && (!correct || !get_string[0]))
	{
		std::cout << info;
		getline(std::cin, get_string);
		if (get_string[0])
		{
			if (info != ADD_SECRET)
				check_string_to_correct_simbols(get_string, correct);
			else
				break ;
		}
	}
}

/*********************************************************************
 *     class Phonebook:      1.1.1. check_string_to_correct_simbols  *
 * *******************************************************************
*/
/* Description:
 *		The function sets parameter "correct" to 1 if string "string" is correct.
 *		Else the function sets parameter "correct" to 0.
*/

void	Contact::check_string_to_correct_simbols(const std::string &string, int &correct)
{
	correct = 1;
	for (int i = 0; string[i]; ++i)
	{
		if (!((string[i] >= 'a' && string[i] <= 'z')||
			  (string[i] >= 'A' && string[i] <= 'Z') || string[i] == '-'))
		{
			std::cout << ADD_INVALID_INPUT << std::endl << std::endl;
			correct = 0;
			break;
		}
	}
}

/*************************************************
 *     class Phonebook:      1.2. get_add_number *
 * ***********************************************
*/
/* Description:
 *		The function prompt the user to input a phone number of contact.
 *		Input must include only integers.
 * Return value:
 * 		Phone number in format std::string.
 * Includes functions:
 *		1.2.1. check_phone_nb_to_correct;
*/

std::string	Contact::get_add_number(int &correct)
{
	std::string	phone_number;

	correct = 1;
	std::cout << ADD_NUMBER_PHONE;
	getline(std::cin, phone_number);
	if (!std::cin.eof())
		correct = check_phone_nb_to_correct(phone_number);
	return (phone_number);
}

/*************************************************
 *     class Phonebook:      1.2. get_add_number *
 * ***********************************************
*/
/* Description:
 *		The function checks parameter "phone_number" for correct symbols.
 * Return value:
 * 		1 - if parameter "phone_number" is correct. Else 0.
 * Includes functions:
 *		1.2.1.1. ft_isdigit;
 *		1.2.1.2. is_hyphen;
*/

int	Contact::check_phone_nb_to_correct(std::string phone_number)
{
	int	bracket = 0;

	for (int i = 0; phone_number[i]; ++i)
	{
		if (i == 0 && phone_number[0] == '+' && ft_isdigit(phone_number[1]))
			++i;
		else if (ft_isdigit(phone_number[i]) || is_hyphen(phone_number, i))
			continue ;
		else if ((!bracket && phone_number[i] == '(')
				|| (bracket == 1 && phone_number[i] == ')'
					&& phone_number[i - 1] != '('))
			++bracket;
		else
		{
			std::cout << ADD_NUMBER_PHONE_ERROR << std::endl;
			return (0) ;
		}
	}
	return (1);
}

/*************************************************
 *     class Phonebook:      1.2.1.1. ft_isdigit *
 * ***********************************************
*/
/* Description:
 *		The function checks if a character is a digit.
 * Return value:
 * 		1 - if a character is a digit. Else 0.
*/

int	Contact::ft_isdigit(const char &c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*************************************************
 *     class Phonebook:      1.2.1.2. ft_isdigit *
 * ***********************************************
*/
/* Description:
 *		The function checks if a character is a hyphen.
 *		Checks if digits are around a hyphen.
 * Return value:
 * 		1 - if a character is a hyphen with digits around. Else 0.
*/

int	Contact::is_hyphen(std::string &phone_number, int &i)
{
	if (phone_number[i] == '-' && i > 0
		&& ft_isdigit(phone_number[i - 1])
		&& ft_isdigit(phone_number[i + 1]))
		return (1);
	return (0);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*********************************************************
 *     class Phonebook:      2. show_contacts_all_name   *
 * *******************************************************
*/
/* Description:
 *		The function displays a list of the available non-empty contacts in 4
 *		columns: index, first name, last name and nickname.
 *		Each column will be 10 chars wide, 
 *		right aligned and separated by a ’|’ character. 
 *		Any output longer than the columns’ width is truncated and the last 
 *		displayable character is replaced by a dot (’.’).
 * Includes functions:
 * 		2.1. print_string_10_char;
*/

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

/*********************************************************
 *     class Phonebook:      2.1. print_string_10_char   *
 * *******************************************************
*/
/* Description:
 *		The function print string (parameter "to_print").
 *		Each column will be 10 chars wide, 
 *		right aligned and separated by a ’|’ character. 
 *		Any output longer than the columns’ width is truncated and the last 
 *		displayable character is replaced by a dot (’.’).
 * Includes functions:
 * 		2.1.1. print_string;
*/

void	Contact::print_string_10_char(const std::string &to_print, char c) 
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

/*********************************************************
 *     class Phonebook:      2.1.1. print_string         *
 * *******************************************************
*/
/* Description:
 *		The function print string (parameter "to_print").
 *		Each column will be 10 chars wide, 
 *		right aligned and separated by a character from parameter "c".
*/

void	Contact::print_string(const std::string &to_print, char c) 
{
	std::cout << std::setw(10) << to_print;
	std::cout << c;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*********************************************************
 *     class Phonebook:      3. show_contact_by_index    *
 * *******************************************************
*/
/* Description:
 *		The function prompts for the index of the desired entry and displays 
 *		the contact’s information, one field per line. If the input makes 
 *		no sense, function displays "Index must be a number from 1 to 8. 
 *		Try again." and prompts for the index of the desired entry.
 *		
 *		If the "index" parameter is 0, this function checks if this contact 
 *		is empty and displays nothing.
 * Return value:
 * 		0 - if the contact is not empty. Else 1.
 * Includes functions:
 * 		3.1. print_string;
*/

int	Contact::show_contact_by_index(int index)
{
	if (!first_name[0])
	{
		if (index)
			std::cout << SHOW_INDEX << index << SHOW_INDEX_EMPTY << std::endl;
		return (1);
	}
	else
	{
		if (0 == index)
			return (0);
		std::cout << SHOW_INDEX << index << ":" << std::endl;
		print_string(first_name);
		print_string(last_name);
		print_string(nickname);
		print_string(phone_number);
		print_string(darkest_secret);
	}
	return (0);
}

/*********************************************************
 *     class Phonebook:      3.1. print_string           *
 * *******************************************************
*/
/* Description:
 *		The function displays string (parameter "to_print") followed by 
 *		a new lineю
*/

void	Contact::print_string(const std::string &to_print) 
{
	std::cout << to_print << std::endl;
}
