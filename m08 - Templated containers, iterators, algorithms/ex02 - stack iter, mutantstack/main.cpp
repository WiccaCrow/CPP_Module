#include "mutantstack.hpp"
#include <iostream>

#include <vector>

void	test_vector_stack();

void    test_color_h1(const std::string text);
void    test_color_h2(const std::string text);
void    test_color_h3(const std::string text);

int main()
{
    test_color_h1(" main ");

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	test_vector_stack();

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

void	test_vector_stack()
{
	MutantStack<int, std::vector<int> > mstack;

	test_color_h3("fill the stack\n");
	for (int i = 5; i; --i)
	{
		mstack.push(i + 10);
	}

	test_color_h3("print the stack (test it++)\n");
	MutantStack<int, std::vector<int> >::iterator it;
	MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
	for (it = mstack.begin(); it != ite; it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << std::endl;

	test_color_h2("test \tit = mstack.begin();");

	test_color_h3("test \t++it\n");
	it = mstack.begin();
	++it;
	std::cout << *it << std::endl;

	test_color_h3("test \tit += 2\n");
	it += 2;
	std::cout << *it << std::endl;

	test_color_h3("test \tit -= 1\n");
	it -=1;
	std::cout << *it << std::endl;

	test_color_h3("test \tit--\n");
	it--;
	std::cout << *it << std::endl;

	test_color_h3("test \t--it\n");
	--it;
	std::cout << *it << std::endl;

	test_color_h3("test \tit + 2\n");
	std::cout << *(it + 2) << std::endl;

	test_color_h3("test \tit - 1\n");
	std::cout << *(it - 1) << std::endl;
}
