#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *dog = new Dog();
	Animal *cat = new Cat();

	((Dog *)dog)->getBrain()->fill_ideas();
	*((Dog*)cat) = *((Dog*)dog);

	((Cat *)cat)->getBrain()->show_ideas();

	delete dog;
	delete cat;

	while (true)
		;
}