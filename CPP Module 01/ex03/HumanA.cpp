/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:33:19 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/07 20:30:06 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string& name, Weapon &type)
{
	_name = name;
	_weapon_type = &type;
};

HumanA::~HumanA(){};

void	HumanA::attack()
{
	std::cout << _name <<  " attacks with their " 
		<< _weapon_type->getType() << std::endl;
}