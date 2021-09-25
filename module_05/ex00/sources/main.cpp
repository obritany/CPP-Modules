#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bur1("Bob", 2);
	std::cout << bur1;
	Bureaucrat bur2(bur1);
	bur2.upgrade();
	std::cout << bur2;

	try
	{
		bur2.upgrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << bur2;

	try
	{
		Bureaucrat bur3("Bob", 200);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}