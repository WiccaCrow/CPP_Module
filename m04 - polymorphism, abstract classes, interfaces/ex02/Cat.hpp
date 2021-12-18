#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{    
    private:
        Brain *cat_ideas;
    public:
        /* Constructs and destructs */
        Cat(void);
        Cat(const Cat &obj);
        virtual ~Cat(void);

        /* operators */
        Cat &    operator=(const Cat &obj);
        /* Set private members */
        void        SetIdea(int i, std::string idea) const;
        /* Get and show private members */
        std::string     GetIdea(int i) const;
        /* other methods */
        virtual void    makeSound(void) const;
};

#endif