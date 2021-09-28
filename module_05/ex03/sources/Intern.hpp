#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &src);
	~Intern();

	Intern &operator=(const Intern &src);

	Form *makeShrubberyForm(std::string target);
	Form *makeRobotomyForm(std::string target);
	Form *makePresidentialForm(std::string target);
	Form *makeForm(std::string type, std::string target);
};

#endif