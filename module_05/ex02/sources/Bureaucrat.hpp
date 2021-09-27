#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Form;
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
private:
	const std::string _name;
	unsigned int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &src);

	void upgrade();
	void downgrade();
	void signForm(Form &form);
	void executeForm(Form const &form);

	std::string getName() const;
	unsigned int getGrade() const;

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);

#endif