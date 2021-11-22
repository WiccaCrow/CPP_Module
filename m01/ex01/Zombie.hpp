#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

# define INPUT_NAME_INVITATION "Enter a name to create zombie horde:\t"
# define INPUT_ERROR_EMPTY "Empty entry."
# define INPUT_N_INVITATION "Enter a number to create zombie horde (number must be from 1 to 9):\t"
# define INPUT_N_ENTRY_HELP "Number must be from 1 to 9. Try again."

class   Zombie 
{
    private:
        std::string name;

    public:
        Zombie(std::string &name_in);
        Zombie(void);
        ~Zombie(void);
        void    announce(void);
};

int     get_nb(void);
void    get_name(std::string &input);
Zombie* zombieHorde( int N, std::string name );

#endif