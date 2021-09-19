#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << std::endl;

	std::cout << animal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	delete cat;
	delete dog;
	delete animal;
	std::cout << std::endl;

	const WrongAnimal *wrong_animal = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();
	std::cout << std::endl;

	std::cout << wrong_animal->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	std::cout << std::endl;

	wrong_animal->makeSound();
	wrong_cat->makeSound();
	std::cout << std::endl;

	delete wrong_cat;
	delete wrong_animal;
	std::cout << std::endl;

	Cat cat1;
	WrongCat wrong_cat1;
}