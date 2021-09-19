#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_hitpoints = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap " << _name << " enters the room.\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitpoints = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap " << _name << " enters the room.\n";
}

ScavTrap::ScavTrap(const ScavTrap &scav_trap) : ClapTrap(scav_trap._name)
{
	*this = scav_trap;
	std::cout << "ScavTrap " << _name << " copy appears.\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " leaves.\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scav_trap)
{
	_name = scav_trap._name;
	_hitpoints = scav_trap._hitpoints;
	_energy = scav_trap._energy;
	_damage = scav_trap._damage;
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	if (_hitpoints <= 0)
		return;

	if (_energy > 0)
	{
		std::cout << "\033[1;31mScavTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!\n\033[0m";
		_energy--;
	}
	else
		std::cout << "\033[1;33mScavTrap " << _name << " doesn't have energy to attack.\n\033[0m";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode.\n";
}