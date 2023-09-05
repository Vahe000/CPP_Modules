/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:38:33 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/15 18:06:51 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string	input_pars(char *input)
{
	std::string	res;

	res = input;
	if (res.find_first_not_of("0123456789/*-+ ") != std::string::npos)
	{
		std::cout << "Error\n";
		res = "";
		return (res);
	}
		
	for (std::string::iterator it = res.begin();  it < res.end(); it++)
	{
		if (*it == ' ')
		{
			res.erase(it);
			--it;
		}
	}
	return (res);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string	valid_input;
		
		valid_input = input_pars(argv[1]);
		if (valid_input.empty())
		{
			std::cout << "Input is empty\n";
			return (1);
		}
		RPN::calculate(valid_input); 	
	}
	else
	{
		std::cout << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return (1);
	}
	return (0);
}