#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	std::cout << "MateriaSource Default constructor\n";
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
	std::cout << "MateriaSource Copy constructor\n";
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete _materias[i];
		_materias[i] = NULL;
	}
	std::cout << "MateriaSource destructor\n";
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return (*this);

	for (int i = 0; i < 4; i++)
	{
		if (src._materias[i] != NULL)
			_materias[i] = src._materias[i]->clone();
	}

	std::cout << "MateriaSource Assignment operator\n";
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			std::cout << "MateriaSource learns " << ((m == NULL) ? "nothing" : m->getType()) << " to slot #" << i << std::endl;
			return;
		}
	}

	std::cout << "\033[1;33mMateriaSource's memory is full\n\033[0m";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] != NULL && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	std::cout << "\033[1;33mMateriaSource does't know " << type << " materia\n\033[0m";
	return (NULL);
}