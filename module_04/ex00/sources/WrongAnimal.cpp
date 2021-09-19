#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal " << _type << " Default constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrong_animal)
{
	*this = wrong_animal;
	std::cout << "WrongAnimal " << _type << " Copy constructor\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << _type << " destructor\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrong_animal)
{
	_type = wrong_animal._type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << _type << ": soundless...\n";
}

std::string WrongAnimal::getType() const
{
	return (_type);
}