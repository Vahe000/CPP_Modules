/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:57:55 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/28 19:02:51 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl		man;
	std::string	input;

	while (true)
	{
		getline(std::cin, input);
		if (input.empty())
			return(1);
		man.complain(input);
	}
}