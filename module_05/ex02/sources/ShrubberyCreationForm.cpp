#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("Unknown", 25, 5, false) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: Form(name, 25, 5, false) {}

ShrubberyCreationForm::ShrubberyCreationForm(const Form &src)
	: Form(src) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);

	new (this) ShrubberyCreationForm(src);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw FormIsNotSignedException();
	if (!isExecutable(executor))
		throw GradeTooLowException();

	std::ofstream file;
	file.open(getName() + "_shrubbery");

	if (file.is_open())
	{
		file << "       _-_" << std::endl;
		file << "    /~~   ~~\\" << std::endl;
		file << " /~~         ~~\\" << std::endl;
		file << "{               }" << std::endl;
		file << " \\  _-     -_  /" << std::endl;
		file << "   ~  \\\\ //  ~" << std::endl;
		file << "_- -   | | _- _" << std::endl;
		file << "  _ -  | |   -_" << std::endl;
		file << "      // \\\\" << std::endl;

		std::cout << "Tree in file " << getName() << "_shrubbery\n";
	}
}