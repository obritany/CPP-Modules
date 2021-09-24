#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice " << _type << " Default constructor\n";
}

Ice::Ice(const Ice &src) : AMateria(src._type)
{
	std::cout << "Ice " << _type << " Copy constructor\n";
}

Ice::~Ice()
{
	std::cout << "Ice " << _type << " destructor\n";
}

Ice &Ice::operator=(const Ice &src)
{
	_type = src._type;
	std::cout << "Ice " << _type << " Assignment operator\n";
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "\033[1;31m* shoots an ice bolt at " << target.getName() << " *\n\033[0m";
}