#include "iter.hpp"

void    test_check_list(void);

int main()
{
    int array_int[8] = {0, 1, 0, 1, 2, 0, 2, 2};
    iter(array_int, 8, print_element);
    std::cout << std::endl;

    iter(array_int, 8, print_int_to_data);
    std::cout << std::endl;

    iter("Happy new year!!!", 17, print_element);
    std::cout << std::endl;

    std::string arr_str_cpp[3] = {
        "Hello!\n",
        "I am glad that you came to the presentation of the project!\n",
        "Thank you. Bye!!!\n"
    };
    iter(arr_str_cpp, 3, print_element);

    test_check_list();


    return (0);
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

    int tab[] = { 0, 1, 2, 3, 4 };
    Awesome tab2[5];

    iter( tab, 5, print );
    iter( tab2, 5, print );
}
