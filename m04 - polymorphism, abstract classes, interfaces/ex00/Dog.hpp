#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{    
    public:
        /* Constructs and destructs */
        Dog(void);
        Dog(const Dog &obj);
        virtual ~Dog(void);

        /* operators */
        Dog &    operator=(const Dog &obj);
        /* Set private members */
        /* Get and show private members */
        /* other methods */
        virtual void    makeSound(void) const;
};

#endif