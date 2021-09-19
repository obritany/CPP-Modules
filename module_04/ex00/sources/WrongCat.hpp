#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &wrong_cat);
	~WrongCat();

	WrongCat &operator=(const WrongCat &wrong_cat);

	void makeSound() const;
};

#endif