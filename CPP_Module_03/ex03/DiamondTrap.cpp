/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:40:48 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/24 19:47:05 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
    _name = "Zara";
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 30;
    _name = ClapTrap::_name + "_clap_name";
    std::cout << "Default constructor for DiamondTrap called\n";
};

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 30;
	_name = ClapTrap::_name + "_clap_name";
	std::cout << "Constructor for DiamondTrap called\n";
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor for DiamondTrap "<< _name << " called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "Copy constructor for DiamondTrap called\n";
	_hit_points = other._hit_points;
    _energy_points = other._energy_points;
    _attack_damage = other._attack_damage;
	_name = other._name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "Copy assignment for DiamondTrap called\n";
    if (this != & rhs)
    {
		_name = rhs._name;
		_hit_points = rhs._hit_points;
		_energy_points = rhs._energy_points;
		_attack_damage = rhs._attack_damage;
    }
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name <<  std::endl;
}