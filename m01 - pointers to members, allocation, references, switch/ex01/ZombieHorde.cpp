#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    // std::string name_new;
    Zombie  *horde = new Zombie[N];
    for (int i = 0; i < N; ++i)
    {
        // name_new = name + std::to_string(i + 1);
        // horde[i] = Zombie(name_new);
        horde[i] = Zombie(name);
    }
    return (horde);
}