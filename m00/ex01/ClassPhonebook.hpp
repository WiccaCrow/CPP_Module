#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP

# include <iostream>
# include "ClassContact.hpp"

# define NB_CONTACTS 8
# define INDEX_INPUT_INVITATION "Enter the index of the desired entry (without spaces or tabs):\t"
# define INDEX_ERROR_EMPTY "Empty entry."
# define INDEX_ENTRY_HELP "Index must be from 1 to 8. Try again."

class Phonebook
{
	private:
		Contact		contact[NB_CONTACTS];

		void		print_table_cap(void);
		void		print_string(std::string string, char c);
		int			take_index(void);

	public:
		void		add(int i);
		void		search(void);
};

#endif