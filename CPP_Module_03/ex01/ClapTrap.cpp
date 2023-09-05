/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:32:23 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/24 15:02:30 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_name = "Arusik";
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "Default constructor for ClapTrap " << _name << " called\n";
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
	std::cout << "Constructor for ClapTrap " << _name << " called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor for ClapTrap " << _name << " called\n";
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
	{
		_name = rhs._name;
		_hit_points = rhs._hit_points;
		_energy_points = rhs._energy_points;
		_attack_damage = rhs._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor for ClapTrap " << _name << " called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (!_hit_points || !_energy_points)
	{
		std::cout << "ClapTrap " << _name << " can't atack\n";
	}
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!\n";
		--_energy_points;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points <= amount)
	{
		std::cout	<< "ClapTrap " << _name << " is died\n";
	}
	else
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points < 1)
    {
        std::cout   << "The ClapTrap " << _name
                    << "has no energy points\n";
        return ;
    }
	_hit_points += amount;
	--_energy_points;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!\n";
}