#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap // virtual for for single ClapTrap creation with multiple inheritance
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scav_trap);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &scav_trap);

	void attack(std::string const &target);
	void guardGate();

	static const int HITPOINTS = 100; // static for child class access without overwrite on creation
	static const int ENERGY = 50;
	static const int DAMAGE = 20;
};

#endif