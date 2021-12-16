#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>

void    test_color(const std::string text);
Base    * generate (void);
void    identify (Base * p);
void    identify (Base & p);

/************/
/*  main    */
/************/
/* Description:
 *      Run prog.
 *
 * contains functions:
 *       1. generate;
 *       2. identify *;
 *       3. identify &;
*/

int main()
{
    Base *ptr = generate();

    identify(ptr);
    identify(*ptr);
    
    delete ptr;
    return (0);
}

/*******************/
/*  1. generate    */
/*******************/
/* Description:
 *      Randomly instanciates A,B or C and returns 
 *      the instance as a Base pointer.
 *
 * contains functions:
 *       1.1. test_color;
*/

Base * generate (void)
{
    test_color("Base * generate (void)\n");
    Base *ptr;

    long int now = time(0);
    now %= 10;

    switch ((static_cast<int>(now) + rand()) % 3)
    {
    case 0:
        ptr = new A;
        std::cout << "Real type A." << std::endl;
        break;
    case 1:
        ptr = new B;
        std::cout << "Real type B." << std::endl;
        break;
    case 2:
        ptr = new C;
        std::cout << "Real type C." << std::endl;
        break;
    default:
        break;
    } ;

    return (ptr);    
}

/*********************/
/*  1.1. test_color  */
/*********************/
/* Description:
 *      Color output.
*/

void    test_color(const std::string text)
{
    std::cout << std::endl << "\033[36m" << text << "\033[0m";
}

/*******************/
/*  2. identify*   */
/*******************/
/* Description:
 *      Displays "A", "B" or "C" according 
 *      to the real type of p.
 *
 * contains functions:
 *       1.1. test_color;
*/

void identify (Base * p)
{
    test_color("void identify (Base * p)\n");

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

/*******************/
/*  3. identify&   */
/*******************/
/* Description:
 *      Displays "A", "B" or "C" according 
 *      to the real type of p.
 *
 * contains functions:
 *       1.1. test_color;
*/

void identify (Base & p)
{
    test_color("void identify (Base & p)\n");
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {    }
    
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch(const std::exception& e)
    {    }
    
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch(const std::exception& e)
    {    }
}
