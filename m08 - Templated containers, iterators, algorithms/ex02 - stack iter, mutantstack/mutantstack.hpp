#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<
    class T, 
    class Container = std::deque<T> 
        >
class MutantStack : public std::stack<T, Container>
{

    public:
        /* iterators */
        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

        /* variables */
        using std::stack<T, Container>::c;

        /*********************************************************************/

        /* Constructs and destructs*/
        MutantStack(void);
        MutantStack(const MutantStack & obj);
        ~MutantStack();

        /* operators */
        MutantStack & operator=(const MutantStack &obj);
        
        /* Set atributs */
        /* Get and show atributs */

        /* other methods */
        iterator begin();
        iterator end();

        const_iterator begin() const { return (c.begin()); }
        const_iterator end() const { return (c.end()); }

        reverse_iterator rbegin() { return (c.rbegin()); }
        reverse_iterator rend() { return (c.rend()); }

        const_reverse_iterator rbegin() const { return (c.rbegin()); }
        const_reverse_iterator rend() const { return (c.rend()); }

};

#include "mutantstack.tpp"

#endif
