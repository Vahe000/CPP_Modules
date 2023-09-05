/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:10:20 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/15 15:14:31 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	Claptrap A;
	Claptrap B(A);
	Claptrap B = A;

	B = A;
	ClapTrap claptrap("Arseen");
	claptrap.attack("Bandit");
	claptrap.takeDamage(1);
	claptrap.beRepaired(10);
	
    return 0;
}
