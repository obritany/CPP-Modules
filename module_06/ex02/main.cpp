#include <iostream>
#include "Classes.hpp"

Base *generate(void)
{
	srand(time(NULL));

	switch (rand() % 3)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A class\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B class\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C class\n";
}

void identify(Base &p)
{
	Base rslt;
	try
	{
		rslt = dynamic_cast<A &>(p);
		std::cout << "A class\n";
	}
	catch (std::exception ex){}
	try
	{
		rslt = dynamic_cast<B &>(p);
		std::cout << "B class\n";
	}
	catch (std::exception ex){}
	try
	{
		rslt = dynamic_cast<C &>(p);
		std::cout << "C class\n";
	}
	catch (std::exception ex){}
}

int main()
{
	Base *rslt = generate();

	std::cout << "Pointer\n";
	identify(rslt);

	std::cout << "Reference\n";
	identify(*rslt);

	return (0);
}