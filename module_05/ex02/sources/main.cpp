#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat brc1("Bob", 1);
	Bureaucrat brc2("John", 150);

	PresidentialPardonForm form("Target");
	PresidentialPardonForm form1(form);

	std::cout << brc1;
	std::cout << brc2;
	std::cout << form1;
	std::cout << std::endl;

	try
	{
		brc1.executeForm(form1);
		brc2.executeForm(form1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	brc1.signForm(form1);
	std::cout << std::endl;

	try
	{
		form1.execute(brc1);
		form1.execute(brc2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	ShrubberyCreationForm form2("Target1");
	RobotomyRequestForm form3("Target2");
	PresidentialPardonForm form4("Target3");

	brc1.signForm(form2);
	brc1.signForm(form3);
	brc1.signForm(form4);

	brc1.executeForm(form2);
	brc1.executeForm(form3);
	brc1.executeForm(form4);

	return (0);
}