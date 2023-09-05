/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:17:30 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/28 19:06:00 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "Animal";
	std::cout << "Default constructor for Animal called\n";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy constructor for Animal called\n";
	*this = other;	
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Copy assignment operator for Animal called\n";
	if (this != &other)
	{
		_type = other._type;
	}
	return(*this);
}

Animal::~Animal()
{
	std::cout << "Destructor for Animal called\n";
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes sound\n";
}

std::string Animal::getType() const
{
	return (_type);
}