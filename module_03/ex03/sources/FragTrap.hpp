#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap // virtual for for single ClapTrap creation with multiple inheritance
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &frag_trap);
	~FragTrap();

	FragTrap &operator=(const FragTrap &frag_trap);

	void attack(std::string const &target);
	void highFivesGuys();

	static const int HITPOINTS = 100; // static for child class access without overwrite on creation
	static const int ENERGY = 100;
	static const int DAMAGE = 30;
};

#endif