#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	std::cout << "Bureaucrat " << _name << " (" << _grade << ") Default constructor\n";
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << _name << " (" << _grade << ") Name constructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
	std::cout << "Bureaucrat " << _name << " (" << _grade << ") Copy constructor\n";
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " (" << _grade << ") destructor\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this == &src)
		return (*this);

	new (this) Bureaucrat(src._name, src._grade);
	std::cout << "Bureaucrat " << _name << " (" << _grade << ") Assignment operator\n";
	return (*this);
}

void Bureaucrat::upgrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::downgrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "\033[1;32mBureaucrat " << _name << " (" << _grade << ") signs form " << form.getName() << " (" << form.getSignGrade() << ")\n\033[0m";
	}
	catch (const std::exception &e)
	{
		std::cout << "Bureaucrat " << _name << " (" << _grade << ") cannot signs form " << form.getName() << " (" << form.getSignGrade() << ") because "
				  << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const Form &form)
{
	try
	{
		form.execute(*this);
		std::cout << "\033[1;32mBureaucrat " << _name << " (" << _grade << ") execute form " << form.getName() << " (" << form.getExecGrade() << ")\n\033[0m";
	}
	catch (const std::exception &e)
	{
		std::cout << "Bureaucrat " << _name << " (" << _grade << ") cannot execute form " << form.getName() << " (" << form.getExecGrade() << ") because "
				  << e.what() << std::endl;
	}
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &src)
{
	cout << "\033[1;36m" << src.getName() << ", bureaucrat grade " << src.getGrade() << "\n\033[0m";
	return (cout);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[1;31mToo high grade\033[0m");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[1;31mToo low grade\033[0m");
}