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
	virtual ~Animal(); // virtual to call all desructors on delete

	Animal &operator=(const Animal &animal);

	virtual void makeSound() const; // virtual to overwrite a function in child classes created as Animal

	std::string getType() const; // const to restrict object variables from changes
};

#endif