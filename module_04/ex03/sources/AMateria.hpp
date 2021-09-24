#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class AMateria;
class ICharacter;
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &src);
	virtual ~AMateria();

	AMateria &operator=(const AMateria &src);

	std::string const &getType() const; // returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif