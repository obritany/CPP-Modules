#include <iostream>
#include "iter.hpp"

int main()
{
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	::iter(nums, 9, ::print);
	std::cout << std::endl;
	::iter(nums, 9, ::doubling);
	::iter(nums, 9, ::print);
	std::cout << std::endl;

	std::cout << std::endl;

	std::string strs[] = {"1s", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s"};

	::iter(strs, 9, ::print);
	std::cout << std::endl;
	::iter(strs, 9, ::doubling);
	::iter(strs, 9, ::print);
	std::cout << std::endl;

	return (0);
}