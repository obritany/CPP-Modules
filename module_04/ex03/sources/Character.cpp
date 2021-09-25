#include "Character.hpp"

Character::Character() : _name("Unknown")
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	std::cout << "Character " << _name << " Default constructor\n";
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	std::cout << "Character " << _name << " Name constructor\n";
}

Character::Character(const Character &src)
{
	*this = src;
	std::cout << "Character " << _name << " Copy constructor\n";
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete _materias[i];
		_materias[i] = NULL;
	}
	std::cout << "Character " << _name << " destructor\n";
}

Character &Character::operator=(const Character &src)
{
	if (this == &src)
		return (*this);

	_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (src._materias[i] != NULL)
			_materias[i] = src._materias[i]->clone();
	}

	std::cout << "Character " << _name << " Assignment operator\n";
	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			std::cout << _name << " takes " << ((m == NULL) ? "nothing" : m->getType()) << " to pocket #" << i << std::endl;
			return;
		}
	}

	std::cout << "\033[1;33m" << _name << "'s inventory is full\n\033[0m";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _materias[idx] == NULL)
	{
		std::cout << "\033[1;33m" << _name << "'s pocket #" << idx << " is empty\n\033[0m";
		return;
	}

	std::cout << _name << " throws out " << _materias[idx]->getType() << " from pocket #" << idx << std::endl;
	_materias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || _materias[idx] == NULL)
	{
		std::cout << "\033[1;33m" << _name << "'s pocket #" << idx << " is empty\n\033[0m";
		return;
	}

	_materias[idx]->use(target);
}