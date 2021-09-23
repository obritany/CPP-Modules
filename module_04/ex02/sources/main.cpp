#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *dog = new Dog();
	dog->makeSound();
	const Animal *cat = new Cat();
	cat->makeSound();
	std::cout << std::endl;

	delete cat;
	delete dog;
	std::cout << std::endl;

	Animal *animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 4; i++)
		delete animals[i];
	
	std::cout << std::endl;

	const Dog dog1;
	dog1.getBrain()->fill_ideas();
	const Dog dog2(dog1);
	dog2.getBrain()->show_ideas();
}