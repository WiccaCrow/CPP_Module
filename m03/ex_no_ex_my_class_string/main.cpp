#include "ClassString_my.hpp"

int main( void )
{
    std::cout << "\n=====\ntest1: \t\t Protect from NULLptr\n";
        String_my AA_t1 = String_my(NULL); 
        std::cout <<  AA_t1 << std::endl; 

    std::cout << "\n=====\ntest2: \t\t \"const_char_str\", char[], char*\n";
        String_my AA2 = String_my("const_char_str"); 
        std::cout << "const_char_str |" << AA2 << '|' << std::endl;

        char str_for_not_const[] = "char[]";
        String_my AA21 = String_my(str_for_not_const); 
        std::cout << "char[]         |" << AA21 << '|' << std::endl;

        char *str_not_const = str_for_not_const;
        String_my AA22 = String_my(str_not_const); 
        std::cout << "char*          |" << AA22 << '|' << std::endl;

    std::cout << "\n=====\ntest3: \t\t String_my(std::string) \n";
        std::string std_str = "some_string_STD::STRING";
        String_my AA3 = String_my(std_str); 
        std::cout <<  AA3 << std::endl; 
    std::cout << "\n=====\ntest4: \t\t copy constucts and operator=:\n";
        String_my AA = AA_t1;
        std::cout << " String_my AA = AA_t1 |" <<  AA 
                << "| \n AA = AA2             |" << (AA=AA2)
                << "| \n AA = AA3             |" << (AA=AA3) 
                << "| \n AA = \"YES\"           |" << (AA="YES") << '|'
                << std::endl;

    std::cout << "\n=====\ntest5: \t\t operator+\n";
        std_str += "+=yes";
        std::cout << " std_str |" <<  std_str << '|' << std::endl;

        AA += "+=yes";
        std::cout << " AA     |" <<  AA << '|' << std::endl;

        std::cout << std::endl;

    return (0);
}