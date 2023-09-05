/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:35:32 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/28 16:39:14 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl		man;

	if (argc != 2)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		return (1);
	}
	man.complain(argv[1]);
}