#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP

# include <iostream>

# define ADD_START "Input a new contact’s information."
# define ADD_NAME_1ST "first name is:\t"
# define ADD_NAME_LAST "last name is:\t"
# define ADD_NAME_NICK "nickname is:\t"
# define ADD_NUMBER_PHONE "phone number is:\t"
# define ADD_SECRET "darkest secret is:\t"
# define ADD_END "End of input."

class Phonebook
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		void	add(void);
		void	search(void);
};

#endif