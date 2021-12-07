#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _Name;
    public:
        /* Constructs and destructs */
        Character(std::string name = "no_name");
        Character(const Character &obj);
        virtual ~Character();
        /* operators */

        Character &   operator=(const Character &obj);

        virtual std::string const & getName() const;
        // virtual void equip(AMateria* m) = 0;
        // virtual void unequip(int idx) = 0;
        // virtual void use(int idx, ICharacter& target) = 0;

        void    show_all(void);
};

#endif