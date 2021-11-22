#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	std::string	&stringREF = str;

	stringPTR = &str;

	std::cout << "address in memory:" << std::endl;
	std::cout << "\tof the string by &str:       " << &str << std::endl;
	std::cout << "\tof the string by stringPTR:  " << stringPTR << std::endl;
	std::cout << "\tof the string by &stringREF: " << &stringREF << std::endl;

	std::cout << "String:" << std::endl;
	std::cout << "\tof the string by &str:       " << str << std::endl;
	std::cout << "\tof the string by *stringPTR: " << *stringPTR << std::endl;
	std::cout << "\tof the string by stringREF:  " << stringREF << std::endl;
}
