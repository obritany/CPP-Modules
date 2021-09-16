#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitpoints = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap " << _name << " enters the room.\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap " << _name << " enters the room.\n";
}

FragTrap::FragTrap(const FragTrap &frag_trap) : ClapTrap(frag_trap._name)
{
	std::cout << "FragTrap " << frag_trap._name << " copy appears.\n";
	*this = frag_trap;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " leaves.\n";
}

FragTrap &FragTrap::operator=(const FragTrap &frag_trap)
{
	_name = frag_trap._name;
	_hitpoints = frag_trap._hitpoints;
	_energy = frag_trap._energy;
	_damage = frag_trap._damage;
	return (*this);
}

void FragTrap::attack(std::string const &target)
{
	if (_hitpoints <= 0)
		return;

	if (_energy > 0)
	{
		std::cout << "\033[1;31mFragTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!\n\033[0m";
		_energy--;
	}
	else
		std::cout << "\033[1;33mFragTrap " << _name << " doesn't have energy to attack.\n\033[0m";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " give fives!\n";
}