#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name("Unknown")
{
	_hitpoints = FragTrap::HITPOINTS;
	_energy = ScavTrap::ENERGY;
	_damage = FragTrap::DAMAGE;
	std::cout << "DiamondTrap " << _name << " enters the room.\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hitpoints = FragTrap::HITPOINTS;
	_energy = ScavTrap::ENERGY;
	_damage = FragTrap::DAMAGE;
	std::cout << "DiamondTrap " << _name << " enters the room.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond_trap) : ClapTrap(diamond_trap._name + "_clap_name")
{
	*this = diamond_trap;
	std::cout << "DiamondTrap " << _name << " copy appears.\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " leaves.\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamond_trap)
{
	ClapTrap::_name = diamond_trap._name + "_clap_name";
	_name = diamond_trap._name;
	_hitpoints = diamond_trap._hitpoints;
	_energy = diamond_trap._energy;
	_damage = diamond_trap._damage;
	return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << _name << " has ClapTrap name " << ClapTrap::_name << ".\n";
}

std::string DiamondTrap::getName()
{
	return (_name);
}

void DiamondTrap::setName(std::string name)
{
	std::cout << "DiamondTrap " << _name << " is a " << name << ".\n";

	ClapTrap::_name = name + "_clap_name";
	_name = name;
}