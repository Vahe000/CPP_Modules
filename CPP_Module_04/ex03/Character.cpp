/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:55:48 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/26 15:16:21 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
	{
		inv[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		droppedinv[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		 inv[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		delete inv[i];
	}
	for (int i = 0; i < 4; i++)
	{
		delete droppedinv[i];
	}
}

Character::Character(std::string const & name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
	{
		inv[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		droppedinv[i] = NULL;
	}
}

Character::Character(const Character& other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other.inv[i])
			inv[i] = other.inv[i]->clone();
	}
}

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for(int i = 0; i < 4; i++)
		{
			delete inv[i];
			inv[i] = 0;
		}
		for (int i = 0; i < 4; i++)
		{
			delete droppedinv[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (rhs.inv[i])
				inv[i] = rhs.inv[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (inv[i] == NULL)
		{
			inv[i] = m;
			return;
		}
	}
	std::cout << "Inventory is already full\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Incorrect index\n";
		return ;
	}
	if (inv[idx] == NULL)
	{
		std::cout << "No Materia are sorted in that index\n";
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (droppedinv[i] == NULL)
		{
			droppedinv[i] = inv[idx];
			inv[idx] = NULL;
			return ;
		}
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && inv[idx])
		inv[idx]->use(target);
}