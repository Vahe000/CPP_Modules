/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:56:29 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/09 17:08:42 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){};

AMateria::AMateria(const AMateria& other)
{
	*this = other;	
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return(*this);
}

AMateria::~AMateria(){};

AMateria::AMateria(std::string const & type)
{
	_type = type;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	 std::cout << "* uses " << _type << " materia on " << target.getName() << " *" << std::endl;
}