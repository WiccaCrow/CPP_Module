#include "main.hpp"

/************/
/*  main    */
/************/
/* Description:
 *      Run prog.
 *
 * contains functions:
 *       1. test_color;
 *       2. serialize;
 *       3. deserialize;
*/

int main()
{
    test_color("Data    *ptr = new Data;");
    Data    *ptr = new Data;

    test_color("ptr->some_str1 = \"Hello!\\n\";");
    test_color("ptr->some_str2 = \"How are you?\";");
    ptr->some_str1 = "Hello!\n";
    ptr->some_str2 = "How are you?";

    test_color("\nptr: ");
    std::cout << ptr;
    test_color("std::cout << ptr->some_str1 << ptr->some_str2 << std::endl;\n");
    std::cout << ptr->some_str1 << ptr->some_str2 << std::endl;
    
    test_color("uintptr_t raw = serialize(ptr);");
    uintptr_t raw = serialize(ptr);

    test_color("Data * ptr_2 = deserialize(raw);");
    Data * ptr_2 = deserialize(raw);

    test_color("\nptr_2: ");
    std::cout << ptr_2;
    test_color("std::cout << ptr_2->some_str1 << ptr_2->some_str2 << std::endl;\n");
    std::cout << ptr_2->some_str1 << ptr_2->some_str2 << std::endl;

    delete ptr_2;
    return (0);
}

/*********************/
/*  1. test_color    */
/*********************/
/* Description:
 *      Color output.
*/

void    test_color(const std::string text)
{
    std::cout << std::endl << "\033[36m" << text << "\033[0m";
}

/********************/
/*  2. serialize    */
/********************/
/* Description:
 *      reinterpret_cast ptr to uintptr_t.
*/

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

/********************/
/*  3. deserialize  */
/********************/
/* Description:
 *      reinterpret_cast uintptr_t to ptr.
*/

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

