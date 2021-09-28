#ifndef ROBOTOMY_FORM_HPP
#define ROBOTOMY_FORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	
	void execute(Bureaucrat const &executor) const;
};

#endif