#include <iostream>
#include "Array.hpp"
#include "stdlib.h"

void    test_check_list(void);

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
// numbers.show_all();
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    test_check_list();
    return 0;
}

/******************************************************************************/
/*                             test_check_list                                */
/******************************************************************************/

class Awesome 
{ 
    public: 
        Awesome(void) : _n(42) { return; } 
        int get(void) const { return this->_n; }        
        
    private: 
        int _n; 
}; 

std::ostream & operator<<(std::ostream & o,const Awesome & rhs) { o << rhs.get() ; return o ; }


template<typename T>
void    print(T const & x) {std::cout << x << std::endl; return; }

void    test_check_list(void)
{
    std::cout << "\n\x1b[30;42m" << "TEST CHECK LIST" << "\x1b[0m" << std::endl;

    Array<Awesome> check(5);

    for (int i = 0; i < 5; i++)
    {
        std::cout << check[i] << "\t";
    }
    std::cout << std::endl << std::endl;

    check.show_all();
    try
    {
        check[6].get();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}