#include "Karen.hpp"

void Karen::debug()
{
	std::cout << "I love to get extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				 "I just love it!\n";
}

void Karen::info()
{
	std::cout << "I cannot believe adding extra bacon cost more money. "
				 "You don’t put enough! If you did I would not have to ask for it!\n";
}

void Karen::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. "
				 "I’ve been coming here for years and you just started working here last month.\n";
}

void Karen::error()
{
	std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

void Karen::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Karen::*func)();

	int index = 0;
	while (levels[index] != level && index < 4)
		index++;

	switch (index)
	{
	case 0:
		func = &Karen::debug;
		break;
	case 1:
		func = &Karen::info;
		break;
	case 2:
		func = &Karen::warning;
		break;
	case 3:
		func = &Karen::error;
		break;
	default:
		std::cout << "It's something else.\n";
		return;
	}
	(this->*func)();
}