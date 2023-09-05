/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:10:20 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/24 12:00:21 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap steve("Steve");

    steve.attack("enemy");
    steve.takeDamage(20);
    steve.beRepaired(10);
    steve.guardGate();
    return (0);
}