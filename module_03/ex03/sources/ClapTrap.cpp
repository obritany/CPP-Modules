#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unknown"), _hitpoints(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap " << _name << " enters the room.\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap " << _name << " enters the room.\n";
}

ClapTrap::ClapTrap(const ClapTrap &clap_trap)
{
	*this = clap_trap;
	std::cout << "ClapTrap " << _name << " copy appears.\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " leaves.\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap_trap)
{
	_name = clap_trap._name;
	_hitpoints = clap_trap._hitpoints;
	_energy = clap_trap._energy;
	_damage = clap_trap._damage;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (_hitpoints <= 0)
		return;

	if (_energy > 0)
	{
		std::cout << "\033[1;31mClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!\n\033[0m";
		_energy--;
	}
	else
		std::cout << "\033[1;33mClapTrap " << _name << " doesn't have energy to attack.\n\033[0m";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitpoints <= 0)
		return;

	_hitpoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage.\n";

	if (_hitpoints <= 0)
		std::cout << "ClapTrap " << _name << " died.\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpoints <= 0)
		return;

	if (_energy > 0)
	{
		std::cout << "\033[1;32mClapTrap " << _name << " heals " << amount << " hitpoints.\033[0m\n";
		_energy--;
	}
	else
		std::cout << "\033[1;33mClapTrap " << _name << " doesn't have energy to heal.\n\033[0m";
}

std::string ClapTrap::getName()
{
	return (_name);
}

int ClapTrap::getDamage()
{
	return (_damage);
}

void ClapTrap::setName(std::string name)
{
	std::cout << "ClapTrap " << _name << " is a " << name << ".\n";
	_name = name;
}

void ClapTrap::getInfo()
{
	std::cout << "ClapTrap " << _name << " info:\n";
	std::cout << "hitpoints " << _hitpoints << std::endl;
	std::cout << "energy " << _energy << std::endl;
	std::cout << "damage " << _damage << std::endl;
}