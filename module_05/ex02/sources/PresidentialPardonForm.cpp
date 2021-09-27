#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("Unknown", 145, 137, false) {}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
	: Form(name, 145, 137, false) {}

PresidentialPardonForm::PresidentialPardonForm(const Form &src)
	: Form(src) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return (*this);

	new (this) PresidentialPardonForm(src);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw FormIsNotSignedException();
	if (!isExecutable(executor))
		throw GradeTooLowException();

	std::cout << getName() << " has been pardoned by Zafod Beeblebrox\n";
}