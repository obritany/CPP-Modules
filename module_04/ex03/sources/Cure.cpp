#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure " << _type << " Default constructor\n";
}

Cure::Cure(const Cure &src) : AMateria(src._type)
{
	std::cout << "Cure " << _type << " Copy constructor\n";
}

Cure::~Cure()
{
	std::cout << "Cure " << _type << " destructor\n";
}

Cure &Cure::operator=(const Cure &src)
{
	_type = src._type;
	std::cout << "Cure " << _type << " Assignment operator\n";
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "\033[1;32m* heals " << target.getName() << "'s wounds *\n\033[0m";
}