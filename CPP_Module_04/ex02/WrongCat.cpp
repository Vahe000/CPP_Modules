#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "Default constructor for WrongCat called\n";
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "Copy constructor for WrongCat called\n";
	*this = other;	
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "Copy assignment operator for WrongCat called\n";
	if (this != &other)
	{
		_type = other._type;
	}
	return(*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor for WrongCat called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Meooow\n";
}

std::string	WrongCat::getType() const
{
	return (_type);
}