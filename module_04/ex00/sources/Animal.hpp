#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &animal);
	~Animal();

	Animal &operator=(const Animal &animal);

	virtual void makeSound() const; // virtual to overwrite a function in child classes created as Animal

	std::string getType() const;
};

#endif