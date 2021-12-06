#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;
    
    public:
        /* Constructs and destructs */
        Animal(const std::string type_in = "none");
        Animal(const Animal &obj);
        virtual ~Animal(void);

        /* operators */
        Animal &    operator=(const Animal &obj);
        /* Set private members */
        /* Get and show private members */
        virtual std::string getType(void) const;
        /* other methods */
        virtual void    makeSound(void) const;
};

#endif