#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &frag_trap);
	~FragTrap();

	FragTrap &operator=(const FragTrap &frag_trap);

	void attack(std::string const &target);
	void highFivesGuys();
};

#endif