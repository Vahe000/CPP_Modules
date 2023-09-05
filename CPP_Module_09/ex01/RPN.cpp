/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:38:56 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/15 18:04:34 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		return (*this);	
	}
	return (*this);	
}

RPN::~RPN(){}

void	RPN::calculate(const std::string& valid_input)
{
	std::stack<int> _numbers;
	
	for (std::string::const_iterator it = valid_input.begin(); it < valid_input.end(); it++)
	{
		if (std::isdigit(*it))
			_numbers.push(*it - '0');
		else
		{
			if (_numbers.size() < 2)
				std::cout << "Bad format\n";
			
			int a = _numbers.top();
			_numbers.pop();
			int b = _numbers.top();
			_numbers.pop();

			switch (*it)
			{
				case '+':
					_numbers.push(b + a);
					break ;
				case '-':
					_numbers.push(b - a);
					break ;
				case '*':
					_numbers.push(b * a);
					break ;
				case '/':
					if (a == 0)
						std::cout << "Division by 0\n";
					_numbers.push(b / a);
					break ;
				default :
					std::cout << "Bad format\n";
			}
		}
	}
	if (_numbers.size() != 1)
		std::cout << "Bad format: Unfinished calculation\n";
	else
	{
		int res = _numbers.top();
		std::cout << res << std::endl;
	}
}