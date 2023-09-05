/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:31:42 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/10 18:25:05 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Default constructor for Cat called\n";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor for Cat called\n";
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy assignment operator for Cat called\n";
	if (this != &other)
	{
		_type = other._type;
	}
	return(*this);
}

Cat::~Cat()
{
	std::cout << "Destructor for Cat called\n";
}

void	Cat::makeSound() const
{
	std::cout << "Meooow\n";
}

std::string	Cat::getType() const
{
	return (_type);
}