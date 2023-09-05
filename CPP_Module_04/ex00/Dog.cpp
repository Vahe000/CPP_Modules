/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:35:12 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/09 18:49:29 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Default constructor for Dog called\n";
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy constructor for Dog called\n";
	*this = other;	
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Copy assignment operator for Dog called\n";
	if (this != &other)
	{
		_type = other._type;
	}
	return(*this);
}

Dog::~Dog()
{
	std::cout << "Destructor for Dog called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Baark\n";
}

std::string	Dog::getType() const
{
	return (_type);
}