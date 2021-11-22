#include "Zombie.hpp"

int main(void)
{
    Zombie *heap_zombie;
    std::string name_on_heap;
    {
        input_name_for_create_on_heap(name_on_heap);
        heap_zombie = newZombie(name_on_heap);
    }
    heap_zombie_use_and_delete(name_on_heap, heap_zombie);

    {
        std::cout << std::endl << "_______________" << std::endl;
        std::cout << "2.1. Zombie on stack: run function " << std::endl;
        std::cout << "\trandomChump(\"Zombie_stack\");" << std::endl;
        randomChump("Zombie_stack");
    }
    return (0);
}

void    input_name_for_create_on_heap(std::string &name_input)
{
    std::cout << "1.1. Making a Pointer for Zombies on the Heap:" << std::endl;
    std::cout << "\tZombie *heap_zombie;" << std::endl;

    std::cout << std::endl;
    std::cout << "1.2. Run a function that create a Zombie on the Heap, name it, ";
    std::cout << "and return it to be used somewhere else in code." << std::endl;
    while (!std::cin.eof())
    {
        std::cout << "Enter a name for the zombie on the Heap (alphabet only): ";
        getline(std::cin, name_input);
        if (name_input[0])
            break ;
    }
    if (std::cin.eof())
        return ;
    std::cout << "heap_zombie = newZombie(" << name_input << ");" << std::endl;
}

void    heap_zombie_use_and_delete(std::string &name, Zombie* &heap_zombie)
{
    std::cout << std::endl;
    std::cout << "1.3. Exit the block in which the zombie " << name << " was created (on the heap)." << std::endl;

    std::cout << std::endl;
    std::cout << "1.4. Use zombie: " << name << std::endl << "heap_zombie->announce();" << std::endl;
    heap_zombie->announce();

    std::cout << std::endl;
    std::cout << "1.5. Run \"delete heap_zombie\"" << std::endl;
    delete heap_zombie;
}