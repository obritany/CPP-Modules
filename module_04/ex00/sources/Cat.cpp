#include "Cat.hpp"

Cat::Cat()
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
	std::cout << "Cat " << _type << " destructor\n";
}

Cat &Cat::operator=(const Cat &cat)
{
	_type = cat._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Cat " << _type << ": MEOW!\n";
}