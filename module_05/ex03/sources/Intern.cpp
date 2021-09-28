#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
		return (*this);

	new (this) Intern();
	return (*this);
}

Form *Intern::makeShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomyForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidentialForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string type, std::string target)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	Form *(Intern::*func_ptr[3])(std::string);
	func_ptr[0] = &Intern::makeShrubberyForm;
	func_ptr[1] = &Intern::makeRobotomyForm;
	func_ptr[2] = &Intern::makePresidentialForm;

	for (int i = 0; i < 3; i++)
	{
		if (types[i] == type)
		{
			std::cout << "\033[1;36mIntern makes " << type << " form\n\033[0m";
			return ((this->*func_ptr[i])(target));
		}
	}

	std::cout << "Unknown " << type << " form\n";
	return (NULL);
}