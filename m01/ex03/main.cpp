#include "Zombie.hpp"

int main(void)
{
    int N = get_nb();
    if (-1 == N)
        return (0);
    
    std::string name;
    get_name(name);
    if (std::cin.eof())
        return (0);

    Zombie* horde = zombieHorde( N, name );
    for (int i = 0; i < N; ++i)
    {
        horde[i].announce();
    }
    delete [] horde;
    return (0);
}

int get_nb(void)
{
    std::string input;

    std::cout << INPUT_N_INVITATION;
	while (!std::cin.eof())
	{
		getline(std::cin, input);
		if (!input[0])
			std::cout << INPUT_ERROR_EMPTY << std::endl 
					  << INPUT_N_ENTRY_HELP << std::endl;
		else if (input[1] 
			|| (!input[1] && (input[0] - '0' < 1 || input[0] - '0' > 9)))
			std::cout << INPUT_N_ENTRY_HELP << std::endl;
		else
			break ;
	}
    if (std::cin.eof())
        return (-1);
	return (input[0] - '0');
}

void get_name(std::string &input)
{
    std::cout << INPUT_NAME_INVITATION;
	while (!std::cin.eof())
	{
		getline(std::cin, input);
		if (!input[0])
			std::cout << INPUT_ERROR_EMPTY << std::endl;
		else
			break ;
	}
}
