/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:44:56 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/15 18:59:01 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	parsArgs(char *arg)
{
	std::string	str;
	char		*end;
	
	str = arg;
	if (arg[0] == '0' && arg[1])
		return false;
	strtol(str.c_str(), &end, 10);
	if(*end != '\0')
		return false;
	return true;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
        std::cout << "Usage: " << argv[0] << " <positive integer sequence>\n";
        return (1);
    }
    std::vector<int> sequence;
    for (int i = 1; i < argc; ++i)
	{
		if(!parsArgs(argv[i]))
		{
			std::cout << "Invalid argument\n";
			return (1);
		}
		long tmp = std::atof(argv[i]);
		if (tmp > INT_MAX)
		{
			std::cout << "Error: too large number\n";
            return 1;	
		}
        int num = std::atoi(argv[i]);
        if (num <= 0)
		{
            std::cout << "Error\n";
            return 1;
        }
        sequence.push_back(num);
    }
	
	sortSequence(sequence, "vector", "deque");

	return 0;
}