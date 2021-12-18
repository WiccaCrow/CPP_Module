#include "Cat.hpp"

/******************************************************************************/
/* Constructors */

//      init

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat: constructor called" << std::endl;
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
}

/******************************************************************************/
/* Operators */

//      =

Cat &    Cat::operator=(const Cat &obj)
{
    std::cout << "Cat:    Assignation operator called " << std::endl;
    if (this != &obj)
        type = obj.getType();
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set private members*/
        /* Get and show private members*/
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