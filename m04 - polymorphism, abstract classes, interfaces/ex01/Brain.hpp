#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#define BRAIN_IDEAS_SIZE 100

class Brain
{
    protected:
        std::string ideas[BRAIN_IDEAS_SIZE];
    public:
        /* Constructs and destructs */
        Brain( void );
        Brain(const Brain &obj);
        ~Brain();
        /* operators */
        Brain & operator=(const Brain &obj);

        /* Set private members */
        void            SetIdeaI(const int &i, const std::string &str_to_cop);

        /* Get and show private members */
        std::string     GetIdeaI(int i) const;

        /* other methods */

};

#endif
