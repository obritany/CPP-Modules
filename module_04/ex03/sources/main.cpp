#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int main()
{
	ICharacter *ichar1 = new Character("Bob");
	ICharacter *ichar2 = new Character("John");
	ichar1->use(2, *ichar1);
	AMateria *ice1 = new Ice();
	ichar1->equip(ice1);
	ichar1->equip(ice1);
	ichar1->use(0, *ichar2);
	ichar1->unequip(0);
	ichar1->unequip(0);
	ichar1->use(0, *ichar2);

	// IMateriaSource *src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter *me = new Character("me");

	// AMateria *tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	// ICharacter *bob = new Character("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);

	// delete bob;
	// delete me;
	// delete src;

	return 0;
}