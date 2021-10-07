#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> *ar1 = new Array<int>(10);

	ar1->_arr[1] = 1;
	ar1->_arr[2] = 2;

	Array<int> *ar2 = new Array<int>(10);

	*ar2 = *ar1;

	for (unsigned int i = 0; i < ar1->_len; i++)
		std::cout << ar1->_arr[i] << std::endl;
	for (unsigned int i = 0; i < ar2->_len; i++)
		std::cout << ar2->_arr[i] << std::endl;

	while(1);

	return (0);
}