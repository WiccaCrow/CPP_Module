#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    typedef struct s_unequip
    {
        AMateria    *tmp_mtr;
        s_unequip   *next;
    }              t_unequip;
    private:
        t_unequip	*ft_lstnew(AMateria *content);
        void	     ft_lstadd_front(t_unequip **lst, t_unequip *new_lst);
        void	     ft_lstclear(t_unequip **lst);

        std::string _Name;
        AMateria      * _inventory[4];
        t_unequip     *garbage_collector;
    public:
        /* Constructs and destructs */
        Character(std::string name = "no_name");
        Character(const Character &obj);
        virtual ~Character();

        /* operators */
        Character &   operator=(const Character &obj);

        /* Set atributs */
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);

        /* Get and show atributs */
        void    show_all(void);
        virtual std::string const & getName() const;

        /* other methods */
        virtual void use(int idx, ICharacter& target);
};

#endif