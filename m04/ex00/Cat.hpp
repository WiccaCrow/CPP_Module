#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

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