#ifndef SHRUBBERY_FORM_HPP
#define SHRUBBERY_FORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const Form &src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
	
	void execute(Bureaucrat const &executor) const;
};

#endif