#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{    
    public:
        /* Constructs and destructs */
        WrongCat(void);
        WrongCat(const WrongCat &obj);
        ~WrongCat(void);

        /* operators */
        WrongCat &    operator=(const WrongCat &obj);
        /* Set private members */
        /* Get and show private members */
        /* other methods */
        void    makeSound(void) const;
};

#endif