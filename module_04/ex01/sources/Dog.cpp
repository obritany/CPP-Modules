#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
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
	delete _brain;
	std::cout << "Dog " << _type << " destructor\n";
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this == &dog)
		return(*this);

	_type = dog._type;

	for (int i = 0; i < 100; i++)
		_brain[i] = dog._brain[i];

	std::cout << "Dog " << _type << " Assignment operator\n";
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Dog " << _type << ": WOOF!\n";
}

Brain *Dog::getBrain() const
{
	return (_brain);
}