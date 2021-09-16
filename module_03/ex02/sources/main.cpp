#include "FragTrap.hpp"

int main()
{
	FragTrap frag1("Batman");
	FragTrap frag2;

	frag2.setName("Joker");
	FragTrap frag3(frag2);

	frag3.attack(frag1.getName());
	frag1.takeDamage(frag3.getDamage());
	frag2.beRepaired(2);
	frag1.highFivesGuys();

	return 0;
}