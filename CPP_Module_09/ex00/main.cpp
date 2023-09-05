/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:06:09 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/15 18:09:06 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		BitcoinExchange	obj;
		obj.dataBaseFill();
		obj.inputRead(argv[1]);
	}
	else
	{
		std::cerr << "Error: could not open file.\n";
		return (1);
	}
	
	return (0);
}