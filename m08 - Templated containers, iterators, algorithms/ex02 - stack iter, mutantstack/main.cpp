#include "mutantstack.hpp"
#include <iostream>

void    test_color_h1(const std::string text);
void    test_color_h2(const std::string text);
void    test_color_h3(const std::string text);

int main()
{
    // test_color_h1(" main ");
	// MutantStack<int> mstack;

	// mstack.push(5);
	// mstack.push(17);

	// std::cout << mstack.top() << std::endl;

	// mstack.pop();

	// std::cout << mstack.size() << std::endl;

	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// //[...]
	// mstack.push(0);

	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();

	// ++it;
	// --it;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// std::stack<int> s(mstack);

    return (0);
}

///////////////////////////////////////////////////////////////

/*********************/
/*     test_color_h */
/*********************/
/* Description:
 *      Color output.
*/

void    test_color_h3(const std::string text)
{
    std::cout << std::endl << "\033[36m" << text << "\033[0m";
}

void    test_color_h1(const std::string text = "test")
{
    std::cout << "\n\x1b[30;42m" << text << "\x1b[0m" << std::endl;
}

void    test_color_h2(const std::string text = "test")
{
    std::cout << "\033[92m" << "  _____________________________________" << std::endl;
    std::cout << "  ||  " << text << std::endl;
    std::cout << "  || \n  \\/ " << "\033[0m" << std::endl;
}


///////////////////////////////////////////////////////////////
