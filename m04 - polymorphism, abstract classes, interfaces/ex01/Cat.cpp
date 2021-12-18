#include "Cat.hpp"

/******************************************************************************/
/* Constructors */

//      init

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat: constructor called" << std::endl;
    cat_ideas = new Brain;
}

//      copy

Cat::Cat(const Cat &obj) : Animal(obj.getType())
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

Cat::~Cat()
{ 
    std::cout << "Cat: destructor called" << std::endl;
    delete cat_ideas;
}

/******************************************************************************/
/* Operators */

//      =

Cat &    Cat::operator=(const Cat &obj)
{
    std::cout << "Cat:    Assignation operator called " << std::endl;
    if (this != &obj)
    {
        type = obj.getType();
        *cat_ideas = *obj.cat_ideas;
    }
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set private members*/
void    Cat::SetIdea(int i, std::string idea) const
{
    cat_ideas->SetIdeaI(i, idea);
}
        /* Get and show private members*/

std::string     Cat::GetIdea(int i) const
{
    return (cat_ideas->GetIdeaI(i));
}
        /* other methods */
void    Cat::makeSound(void) const
{

    std::cout << "Cat: Murrrrr-Mrrr.... " << std::endl;
    std::cout <<  "\033[0;36m      (.`.\n" 
              <<  "       )...)\n"
              <<  "      (....)\n"
              <<  "       \\...\\\n"
              <<  "        \\...\\.\n"
              <<  "    __--.'......`.-....\n"
              <<  "  /...................`.....          .\n"
              <<  " (............)............`..-.._   ,.\\         _\n"
              <<  "  )........,.'.......................(...\\.-.-.'.(\n"
              <<  "  \\......(...................)..../.............\\.\n"
              <<  "    \\.....\\._.(.........../....(........\033[0;33m<6\033[0;36m....\033[0;33m(6\033[0;36m|\n"
              <<  "      \\._.).).).\\........(.......`.._.........:Y.).__\n"
              <<  "                    \\........`-..._....'..-..-.-^.‘_.).).)\n"
              <<  "                       `.-..._...).).) \033[0mMurrrrr-Mrrr...."
              << std::endl;
}