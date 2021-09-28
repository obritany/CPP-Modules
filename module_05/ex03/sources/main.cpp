#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat brc1("Bob", 1);
	Intern intr1;

	Form *form1 = intr1.makeForm("shrubbery creation", "Target1");
	Form *form2 = intr1.makeForm("robotomy request", "Target1");
	Form *form3 = intr1.makeForm("presidential pardon", "Target1");

	brc1.signForm(*form1);
	brc1.signForm(*form2);
	brc1.signForm(*form3);

	brc1.executeForm(*form1);
	brc1.executeForm(*form2);
	brc1.executeForm(*form3);

	return (0);
}