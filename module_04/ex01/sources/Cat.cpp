#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	_type = "Cat";
	std::cout << "Cat " << _type << " Default constructor\n";
}

Cat::Cat(const Cat &cat)
{
	*this = cat;
	std::cout << "Cat " << _type << " Copy constructor\n";
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat " << _type << " destructor\n";
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return (*this);

	_type = cat._type;

	for (int i = 0; i < 100; i++)
		_brain[i] = cat._brain[i];

	std::cout << "Cat " << _type << " Assignment operator\n";
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat " << _type << ": MEOW!\n";
}

Brain *Cat::getBrain() const
{
	return (_brain);
}