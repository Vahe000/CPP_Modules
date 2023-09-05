/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:33:48 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/25 17:49:22 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
};

HumanB::HumanB(){};
HumanB::~HumanB(){};

void HumanB::setWeapon(Weapon &type)
{
    _weapon_type = &type;
}

void	HumanB::attack()
{
	std::cout << _name <<  " attacks with their "
		<< _weapon_type->getType() << std::endl;
}