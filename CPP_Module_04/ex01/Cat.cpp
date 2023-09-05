/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:31:42 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/10 14:57:49 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Default constructor for Cat called\n";
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor for Cat called\n";
	_brain = new Brain();
	*this = other;	
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Copy assignment operator for Cat called\n";
    if (this != &other)
    {
		delete _brain;
        _type = other._type;
        _brain = new Brain(*other._brain);
    }
    return (*this);
}

Cat::~Cat()
{
	delete _brain;
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