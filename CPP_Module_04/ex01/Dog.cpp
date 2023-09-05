/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:35:12 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/10 15:01:07 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Default constructor for Dog called\n";
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy constructor for Dog called\n";
	_brain = new Brain();
	*this = other;	
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Copy assignment operator for Dog called\n";
    if (this != &other)
    {
		delete _brain;
        _type = other._type;
        _brain = new Brain(*other._brain);
    }
    return (*this);
}

Dog::~Dog()
{
	delete _brain;
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