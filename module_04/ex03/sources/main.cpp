#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	// Subject test
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;

	// My test
	ICharacter *ichar1 = new Character("Bob");
	ICharacter *ichar2 = new Character("John");
	std::cout << std::endl;

	ichar1->use(2, *ichar1);
	AMateria *ice1 = new Ice();
	ichar1->equip(ice1);
	ichar1->use(0, *ichar2);
	std::cout << std::endl;

	ICharacter *ichar3 = new Character(*(Character *)ichar1);
	ichar3->use(0, *ichar2);
	ichar1->unequip(0);
	ichar1->unequip(1);
	ichar1->use(0, *ichar2);
	ichar3->use(0, *ichar2);
	std::cout << std::endl;

	return (0);
}