#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP

# include <iostream>
# include "ClassContact.hpp"

# define NB_CONTACTS 8

class Phonebook
{
	private:
		int			i_add;
		int			index;
		Contact		ph_book[NB_CONTACTS];

	public:
		void	add(void);
		void	search(void);
};

#endif