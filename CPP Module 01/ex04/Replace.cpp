/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:45:45 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/29 17:07:34 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string fileName, std::string s1, std::string s2)
{
    _fileName   = fileName;
    _s1         = s1;
    _s2         = s2;
}

Replace::~Replace(){};

void	Replace::replace_string()
{
	std::string	pre_rep;
	size_t		index;
	bool		flag;

	index = pre_rep.find(_s1);
	std::ifstream 	infile(_fileName);
	if (!infile.is_open())
	{
		std::cerr << "Unable to open file." << std::endl;
        return ;
	}
	std::ofstream new_file(_fileName + ".replace");
	while (!infile.eof())
	{
		if (flag == true)
			new_file << "\n";
		getline(new_file, pre_rep);
		index = pre_rep.find(_s1);
		while (index != std::string::npos)
		{
			pre_rep.erase(index, _s1.length());
			pre_rep.insert(index, _s2);
			index = pre_rep.find(_s1);
		}
		if (!infile.eof())
			flag = true;
		new_file << pre_rep;
	}	
}