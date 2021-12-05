#ifndef CLASS_CAT_HPP
# define CLASS_CAT_HPP

# include <iostream>
# include "ClassAnimal.hpp"

class Cat : public Animal
{    
    public:
        /* Constructs and destructs */
        Cat(void);
        Cat(const Cat &obj);
        virtual ~Cat(void);

        /* operators */
        Cat &    operator=(const Cat &obj);
        /* Set private members */
        /* Get and show private members */
        /* other methods */
        virtual void    makeSound(void) const;
};

#endif