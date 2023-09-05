/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:28:36 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/24 15:04:56 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	_name = "Janibek";
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "Default constructor for FragTrap " << _name << " called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "Constructor for FragTrap " << _name << " called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor for FragTrap " << _name << " called\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "Copy constructor for FragTrap " << _name << " called\n";
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "Copy assignment operator for FragTrap called" << std::endl;
	ClapTrap::operator=(rhs);
	return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "High five, guys!" << std::endl;
}