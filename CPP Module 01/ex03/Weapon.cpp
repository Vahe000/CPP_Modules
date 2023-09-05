/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:35:11 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/25 16:43:59 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){};

Weapon::Weapon(std::string a)
{
	_type = a;	
}

Weapon::~Weapon(){};

const std::string&	Weapon::getType()
{
	return (_type);
}

void Weapon::setType(std::string type_name)
{
    _type = type_name;
}