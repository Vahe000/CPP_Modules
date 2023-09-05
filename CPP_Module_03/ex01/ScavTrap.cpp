/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:18:01 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/24 15:02:41 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "Setrak";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "Default constructor for ScavTrap " << _name << " called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "Constructor for ScavTrap " << _name << " called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "Copy constructor for ScavTrap " << _name << " called\n";
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << "Copy assignment operator for ScavTrap called" << std::endl;
 	ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor for ScavTrap " << _name << " called\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (!_hit_points || !_energy_points)
	{
		std::cout << "ScavTrap " << _name << " can't atack\n";
	}
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!\n";
		--_energy_points;
	}
}

void ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}