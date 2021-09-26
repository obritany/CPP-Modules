#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	const unsigned int _grade_sign;
	const unsigned int _grade_exec;
	bool _is_signed;

public:
	Form();
	Form(std::string name, unsigned int grade_sign, unsigned int grade_exec, bool is_signed);
	Form(const Form &src);
	~Form();

	Form &operator=(const Form &src);

	void beSigned(Bureaucrat &bureaucrat);

	std::string getName() const;
	unsigned int getSignGrade() const;
	unsigned int getExecGrade() const;
	bool isSigned() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif