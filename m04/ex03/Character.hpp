#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _Name;
        AMateria    * _inventory[4];
    public:
        /* Constructs and destructs */
        Character(std::string name = "no_name");
        Character(const Character &obj);
        virtual ~Character();
        /* operators */

        Character &   operator=(const Character &obj);

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        // virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target);

        void    show_all(void);
        AMateria    *get_inventory_i_clone(int i) const;
};

#endif