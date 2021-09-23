#include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria")
{
	std::cout << "AMateria " << _type << " Default constructor\n";
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria " << _type << " Type constructor\n";
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
	std::cout << "AMateria " << _type << " Copy constructor\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria " << _type << " destructor\n";
}

AMateria &AMateria::operator=(const AMateria &src)
{
	_type = src._type;
	std::cout << "AMateria " << _type << " Assignment operator\n";
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* nothing happens with " << target.getName() << " *\n";
}