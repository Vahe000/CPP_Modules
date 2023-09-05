/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:30:06 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/10 18:44:43 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		inv[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if (inv[i] != NULL)
            delete inv[i];
        inv[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
     for(int i = 0; i < 4; i++)
        inv[i] = NULL;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        for(int i = 0; i < 4; i++)
        {
            if (inv[i] != NULL)
                delete inv[i];
            inv[i] = NULL;
        }
        for(int i = 0; i < 4 && rhs.inv[i]; i++)
            inv[i] = rhs.inv[i]->clone();
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (inv[i] == NULL)
		{
			inv[i] = mat;
			return ;
		}
	}
	std::cout << "Inventory is already full\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (inv[i] != NULL && inv[i]->getType() == type)
		{
			return (inv[i]->clone());
		}
	}
	return (0);
}