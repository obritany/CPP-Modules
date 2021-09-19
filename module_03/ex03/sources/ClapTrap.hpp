#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	int _hitpoints;
	int _energy;
	int _damage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clap_trap);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &clap_trap);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName();
	int getDamage();

	void setName(std::string name);
	void getInfo();
};

#endif