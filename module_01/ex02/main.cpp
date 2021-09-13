#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address\t\t" << &string << std::endl;
	std::cout << "Pointer\t\t" << stringPTR << std::endl;
	std::cout << "Reference\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "String pointer\t\t" << *stringPTR << std::endl;
	std::cout << "String reference\t" << stringREF << std::endl;

	return (0);
}