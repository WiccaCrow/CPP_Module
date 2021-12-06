#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{    
    private:
        Brain   *dog_ideas;
    public:
        /* Constructs and destructs */
        Dog(void);
        Dog(const Dog &obj);
        virtual ~Dog(void);

        /* operators */
        Dog &           operator=(const Dog &obj);
        /* Set private members */
        void        SetIdea(int i, std::string idea) const;
        /* Get and show private members */
        std::string     GetIdea(int i) const;
        /* other methods */
        virtual void    makeSound(void) const;
};

#endif