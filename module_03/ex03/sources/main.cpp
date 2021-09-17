#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond1("Batman");
	DiamondTrap diamond2;

	diamond2.setName("Joker");
	DiamondTrap diamond3(diamond2);

	diamond3.attack(diamond1.getName());
	diamond1.takeDamage(diamond3.getDamage());
	diamond2.beRepaired(2);
	diamond1.guardGate();
	diamond1.highFivesGuys();
	diamond1.whoAmI();

	return 0;
}