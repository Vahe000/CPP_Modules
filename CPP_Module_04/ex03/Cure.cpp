#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	_type = "cure";
}

Cure::Cure(const Cure& other)
{
	*this = other;	
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return(*this);
}

Cure::~Cure(){};

Cure* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals bob's wounds " << target.getName() << " *";
}