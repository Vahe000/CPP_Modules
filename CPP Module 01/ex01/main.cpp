/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:55:34 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/28 18:05:47 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int		N;
    Zombie	*z;

	N = 3;
	z = zombieHorde(N, "Zombie");
	for (int i = 0; i < N; ++i)
		z->announce();
	delete []z;
	return (0);
}
