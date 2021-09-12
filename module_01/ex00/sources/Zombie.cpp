#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "\033[1;32mZombie " << _name << " enter the room\n\033[0m";
}

Zombie::~Zombie()
{
	std::cout << "\033[1;31mZombie " << _name << " leave\n\033[0m";
}

void Zombie::announce()
{
	std::cout << _name << " BraiiiiiiinnnzzzZ...\n";
}
