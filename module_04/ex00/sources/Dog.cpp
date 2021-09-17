#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog " << _type << " Default constructor\n";
}

Dog::Dog(const Dog &dog)
{
	*this = dog;
	std::cout << "Dog " << _type << " Copy constructor\n";
}

Dog::~Dog()
{
	std::cout << "Dog " << _type << " destructor\n";
}

Dog &Dog::operator=(const Dog &dog)
{
	_type = dog._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog " << _type << ": WOOF!\n";
}