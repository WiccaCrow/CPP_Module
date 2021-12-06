#include "Brain.hpp"

/******************************************************************************/
/* Constructors */

//      init

Brain::Brain(void)
{
    std::cout << "Brain: constructor called" << std::endl;
}

//      copy

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain: Copy constructor called" << std::endl;
    operator=(obj);
}

/******************************************************************************/
/* Destructors */

Brain::~Brain()
{ 
    std::cout << "Brain: destructor called" << std::endl;
}

/******************************************************************************/
/* Operators */

//      =

Brain &    Brain::operator=(const Brain &obj)
{
    std::cout << "Brain:    Assignation operator called " << std::endl;
    if (this != &obj)
        for (int i = 0; i < 100;++i)
            ideas[i] = obj.GetIdeaI(i);
    return (*this);
}

/******************************************************************************/
/* Private functions */


/******************************************************************************/
/* Public functions */

        /* Set private members*/
void            Brain::SetIdeaI(const int &i, const std::string &str_to_copy)
{
    if (i > 99)
    {
        std::cout << "Warning: i must be from 0 to 99. Nothing to copy" 
                  << std::endl;
        return ;
    }
    ideas[i] = str_to_copy;
}


        /* Get and show private members*/
std::string     Brain::GetIdeaI(int i) const
{
    if (i > 99)
    {
        std::cout << "Warning: i must be from 0 to 99. I giving you empty idea not from brain" 
                  << std::endl;
        return ("");
    }
    return ideas[i];
}

        /* other methods */
