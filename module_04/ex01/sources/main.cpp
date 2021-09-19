#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << std::endl;
	
	delete cat;
	delete dog;
	std::cout << std::endl;

	const Animal *dog1 = new Dog();
	((Dog *)dog1)->getBrain()->fill_ideas();

	const Animal *dog2 = new Dog();
	*((Dog *)dog2) = *((Dog *)dog1);

	const Animal *dog3 = new Dog(*((Dog *)dog2));
	((Dog *)dog3)->getBrain()->show_ideas();

	delete dog3;
	delete dog2;
	delete dog1;

	while (true)
		;
}