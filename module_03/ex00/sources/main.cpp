#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("Batman");
	ClapTrap clap2;

	clap2.setName("Joker");
	ClapTrap clap3(clap2);

	clap3.attack(clap1.getName());
	clap1.takeDamage(clap3.getDamage());
	clap2.beRepaired(2);

	return 0;
}