#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	std::cout << "Bureaucrat " << _name << " (" << _grade << ") Default constructor\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
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
	_name = src._name;
	_grade = src._grade;
	std::cout << "Bureaucrat " << _name << " (" << _grade << ") Assignment operator\n";
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
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