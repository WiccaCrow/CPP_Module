#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

# define ADD_START "Input a new contact’s information."
# define ADD_NAME_1ST "first name is:\t"
# define ADD_NAME_LAST "last name is:\t"
# define ADD_NAME_NICK "nickname is:\t"
# define ADD_NUMBER_PHONE "phone number is:\t"
# define ADD_SECRET "darkest secret is:\t"
# define ADD_END "End of input."
# define ADD_NUMBER_PHONE_ERROR "\nERROR: Incorrect number format. Try again. \nCorrect example: +7(999)666666, 8(999)666666, 8999666666, \n                 8-999-666666, 8(999)666-666. \n\nSome incorrect example: (799)66666, +(999)-666666, ()96066 etc.\n"
# define ADD_INVALID_INPUT "Invalid input.\nAllowed: letters in any case and the symbol '-'.\nTry again."
# define SHOW_INDEX "The contact with index "
# define SHOW_INDEX_EMPTY " is empty. Try SEARCH again."

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		
		void	    add_string(const char info[], std::string &get_string);
		void		check_string_to_correct_simbols(const std::string &string, int &correct);
		std::string	get_add_number(int &correct);
		int			check_phone_nb_to_correct(std::string phone_number);
		int			ft_isdigit(const char &c);
		int			is_hyphen(std::string &phone_number, int &i);
		void		print_string_10_char(const std::string &to_print, char c = '\n');
		void		print_string(const std::string &to_print, char c);
		void		print_string(const std::string &to_print);

	public:
        void	add();
        void	show_contacts_all_name(int index);
		int		show_contact_by_index(int index);
};

#endif