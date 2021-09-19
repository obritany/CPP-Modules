#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &wrong_animal);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &wrong_animal);

	void makeSound() const;

	std::string getType() const;
};

#endif