#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP

# include <iostream>
# include "ClassContact.hpp"

# define NB_CONTACTS 8

class Phonebook
{
	private:
		// int			i_add;
		// int			index;
		Contact		contact[NB_CONTACTS];

	public:
		// Phonebook();
		void	add(int i);
		void	search(void);
		// ~Phonebook();
};


#endif