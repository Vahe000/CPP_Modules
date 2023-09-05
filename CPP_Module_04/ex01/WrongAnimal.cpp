#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << "Default constructor for WrongAnimal called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy constructor for WrongAnimal called\n";
	*this = other;	
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "Copy assignment operator for WrongAnimal called\n";
	if (this != &other)
	{
		_type = other._type;
	}
	return(*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor for WrongAnimal called\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes sound\n";
}

std::string WrongAnimal::getType() const
{
	return (_type);
}