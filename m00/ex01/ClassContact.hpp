#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP

# include <iostream>

# define ADD_START "Input a new contact’s information."
# define ADD_NAME_1ST "first name is:\t"
# define ADD_NAME_LAST "last name is:\t"
# define ADD_NAME_NICK "nickname is:\t"
# define ADD_NUMBER_PHONE "phone number is:\t"
# define ADD_SECRET "darkest secret is:\t"
# define ADD_END "End of input."
# define ADD_NUMBER_PHONE_ERROR "\nERROR: Incorrect number format. Try again. \nCorrect example: +7(999)666666, 8(999)666666, 8999666666, \n                 8-999-666666, 8(999)666-666. \n\nSome incorrect example: (799)66666, +(999)-666666, ()96066 etc.\n"

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
        void    add(void);
        void    show(void);
};

#endif