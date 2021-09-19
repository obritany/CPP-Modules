#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat " << _type << " Default constructor\n";
}

WrongCat::WrongCat(const WrongCat &wrong_cat)
{
	*this = wrong_cat;
	std::cout << "WrongCat " << _type << " Copy constructor\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << _type << " destructor\n";
}

WrongCat &WrongCat::operator=(const WrongCat &wrong_cat)
{
	_type = wrong_cat._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat " << _type << ": MEOW!\n";
}