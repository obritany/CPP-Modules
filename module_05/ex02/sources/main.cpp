#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat brc1("Bob", 50);
	Bureaucrat brc2("John", 100);

	Form form1("Form1", 75, 75, false);
	std::cout << brc1;
	std::cout << brc2;
	std::cout << form1;
	std::cout << std::endl;

	try
	{
		brc1.signForm(form1);
		brc2.signForm(form1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		form1.beSigned(brc1);
		form1.beSigned(brc2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}