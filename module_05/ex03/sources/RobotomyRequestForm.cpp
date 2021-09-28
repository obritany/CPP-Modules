#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("Unknown", 72, 45, false) {}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: Form(name, 72, 45, false) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: Form(src) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return (*this);

	new (this) RobotomyRequestForm(src);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw FormIsNotSignedException();
	if (!isExecutable(executor))
		throw GradeTooLowException();

	srand(time(NULL));
	if (rand() % 2)
		std::cout << getName() << " has been robotomized successfully\n";
	else
		std::cout << "It's a failure\n";
}