#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav1("Batman");
	ScavTrap scav2;

	scav2.setName("Joker");
	ScavTrap scav3(scav2);

	scav3.attack(scav1.getName());
	scav1.takeDamage(scav3.getDamage());
	scav2.beRepaired(2);
	scav1.guardGate();

	return 0;
}