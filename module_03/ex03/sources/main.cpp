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
	std::cout << std::endl;

	ClapTrap ct("ClapTest");
	ct.getInfo();
	std::cout << std::endl;

	ScavTrap st("ScavTest");
	st.getInfo();
	std::cout << std::endl;

	DiamondTrap dt("DiamondTest");
	dt.getInfo();
	std::cout << std::endl;

	return 0;
}