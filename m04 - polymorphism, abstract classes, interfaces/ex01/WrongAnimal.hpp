#ifndef CLASS_WRONGANIMAL_HPP
# define CLASS_WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    
    public:
        /* Constructs and destructs */
        WrongAnimal(const std::string type_in = "WrongAnimal");
        WrongAnimal(const WrongAnimal &obj);
        virtual ~WrongAnimal(void);

        /* operators */
        WrongAnimal &    operator=(const WrongAnimal &obj);
        /* Set private members */
        /* Get and show private members */
        virtual std::string getType(void) const;
        /* other methods */
        void    makeSound(void) const;
};

#endif