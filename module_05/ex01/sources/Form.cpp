#include "Form.hpp"

Form::Form() : _name("Unknown"), _grade_sign(150), _grade_exec(150), _is_signed(false)
{
	std::cout << "Form " << _name << " (" << _grade_sign << "," << _grade_exec << "," << _is_signed << ") Default constructor\n";
}

Form::Form(std::string name, unsigned int grade_sign, unsigned int grade_exec, bool is_signed)
	: _name(name), _grade_sign(grade_sign), _grade_exec(grade_exec), _is_signed(is_signed)
{
	if (_grade_sign < 1 || _grade_exec < 1)
		throw GradeTooHighException();
	if (_grade_sign > 150 || _grade_exec > 150)
		throw GradeTooLowException();

	std::cout << "Form " << _name << " (" << _grade_sign << "," << _grade_exec << "," << _is_signed << ") Name constructor\n";
}

Form::Form(const Form &src)
	: _name(src._name), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec), _is_signed(src._is_signed)
{
	std::cout << "Form " << _name << " (" << _grade_sign << "," << _grade_exec << "," << _is_signed << ") Copy constructor\n";
}

Form::~Form()
{
	std::cout << "Form " << _name << " (" << _grade_sign << "," << _grade_exec << "," << _is_signed << ") destructor\n";
}

Form &Form::operator=(const Form &src)
{
	if (this == &src)
		return (*this);

	new (this) Form(src);
	std::cout << "Form " << _name << " (" << _grade_sign << "," << _grade_exec << "," << _is_signed << ") Assignment operator\n";
	return (*this);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_sign)
		_is_signed = true;
	else
		throw GradeTooLowException();
}

std::string Form::getName() const
{
	return (_name);
}

unsigned int Form::getSignGrade() const
{
	return (_grade_sign);
}

unsigned int Form::getExecGrade() const
{
	return (_grade_exec);
}

bool Form::isSigned() const
{
	return (_is_signed);
}

std::ostream &operator<<(std::ostream &cout, const Form &src)
{
	cout << "\033[1;36mForm " << src.getName() << " (" << src.getSignGrade() << "," << src.getExecGrade() << "," << src.isSigned() << ")\n\033[0m";
	return (cout);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("\033[1;31mToo high grade\033[0m");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("\033[1;31mToo low grade\033[0m");
}