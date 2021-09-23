#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal " << _type << " Default constructor\n";
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
	std::cout << "Animal " << _type << " Copy constructor\n";
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << " destructor\n";
}

Animal &Animal::operator=(const Animal &animal)
{
	_type = animal._type;
	std::cout << "Animal " << _type << " Assignment operator\n";
	return (*this);
}

std::string Animal::getType() const
{
	return (_type);
}