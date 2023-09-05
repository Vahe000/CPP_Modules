/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:41:16 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/10 15:22:50 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	_type = "ice";
}

Ice::Ice(const Ice& other)
{
	*this = other;	
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

Ice::~Ice(){};

Ice* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}