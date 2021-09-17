#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap	// Order - FragTrap rewrite same ScavTrap values in ClapTrap
{
private:
	std::string _name;

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamond_trap);
	~DiamondTrap();

	DiamondTrap &operator=(const DiamondTrap &diamond_trap);

	void attack(std::string const &target);
	void whoAmI();

	std::string getName();

	void setName(std::string name);
};

#endif