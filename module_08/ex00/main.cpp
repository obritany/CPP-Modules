#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	std::vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);

	try
	{
		std::vector<int>::const_iterator rslt1 = easyfind(test, 2);
		std::cout << *rslt1 << std::endl;

		std::vector<int>::const_iterator rslt2 = easyfind(test, 7);
		std::cout << *rslt2 << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cerr << "Not found!\n";
	}
}