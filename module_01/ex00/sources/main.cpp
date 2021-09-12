#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	// Zombie on heap
	Zombie *newZombie1 = newZombie("MikeHeap");
	newZombie1->announce();
	Zombie *newZombie2 = new Zombie("JackHeap");
	newZombie2->announce();
	
	delete newZombie1;
	delete newZombie2;

	// Zombie on stack
	randomChump("SmithStack");
	Zombie zombie("BobStack");
	zombie.announce();

	return (0);
}