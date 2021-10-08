#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main()
{
	// Subject test
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	// Scope
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return (1);
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete[] mirror;
	std::cout << std::endl;

	// My test
	Array<int> *ar1 = new Array<int>(10);
	std::cout << "Array size: " << (*ar1).size() << std::endl;

	(*ar1)[1] = 1;
	(*ar1)[2] = 2;

	Array<int> *ar2 = new Array<int>(10);

	*ar2 = *ar1;

	for (unsigned int i = 0; i < 10; i++)
		std::cout << (*ar1)[i] << std::endl;

	std::cout << std::endl;

	for (unsigned int i = 0; i < 10; i++)
		std::cout << (*ar2)[i] << std::endl;

	return (0);
}