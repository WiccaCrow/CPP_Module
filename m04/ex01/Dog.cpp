#include "Dog.hpp"

/******************************************************************************/
/* Constructors */

//      init

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog: constructor called" << std::endl;
    dog_ideas = new Brain;
}

//      copy

Dog::Dog(const Dog &obj) : Animal(obj.getType())
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

Dog::~Dog()
{ 
    std::cout << "Dog: destructor called" << std::endl;
    delete dog_ideas;
}

/******************************************************************************/
/* Operators */

//      =

Dog &    Dog::operator=(const Dog &obj)
{
    std::cout << "Dog:    Assignation operator called " << std::endl;
    if (this != &obj)
    {
        type = obj.getType();
        *dog_ideas = *obj.dog_ideas;
    }
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set private members*/

void    Dog::SetIdea(int i, std::string idea) const
{
    dog_ideas->SetIdeaI(i, idea);
}
        /* Get and show private members*/

std::string     Dog::GetIdea(int i) const
{
    return (dog_ideas->GetIdeaI(i));
}

        /* other methods */
void    Dog::makeSound(void) const
{
    std::cout << "Dog: GAV-GAV " << std::endl;
    std::cout << "\033[1;30m             _=,_              \n"
              << "          o_/\033[0;33m6\033[1;30m /#\\            \n"
              << "   \033[0;33mAv-Av\033[1;30m  \\__ |##/            \n"
              << "           ='|--\\             \n"
              << "             /   #'-.     |    \n"
              << "             \\#|_   _'-. /    \n"
              << "             |/ \\_( # _|      \n"
              << "            C/ ,--___/         \033[0m"
              << std::endl;
}