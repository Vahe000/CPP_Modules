/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:10:46 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/14 15:55:09 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(){};
PhoneBook::~PhoneBook(){};

void	PhoneBook::init_data()
{
	static	int		i;
	char            *ptr;
	std::string	    tmp[5];

	if (i == 8)
		i = 0;
	std::cout << "Please enter first name  " << std::endl;
    while (getline(std::cin, tmp[0]) && tmp[0].empty())
        std::cout << "Line is empty. Please try again" << std::endl;
	std::cout << "Please enter last name  " << std::endl;
    while (getline(std::cin, tmp[1]) && tmp[1].empty())
        std::cout << "Line is empty" << std::endl;
	std::cout << "Please enter nickname  " << std::endl;
    while (getline(std::cin, tmp[2]) && tmp[2].empty())
        std::cout << "Line is empty" << std::endl;
	std::cout << "Please enter phone number  " << std::endl;
    while (getline(std::cin, tmp[3]) && tmp[3].empty())
        std::cout << "Line is empty" << std::endl;
	strtol(tmp[3].c_str(),&ptr,10);
	if(*ptr != '\0')
	{
		std::cout << "Phone number must be numeric" << std::endl;
		return ;	
	}
	std::cout << "Please enter darkest secret  " << std::endl;
    while (getline(std::cin, tmp[4]) && tmp[4].empty())
        std::cout << "Line is empty" << std::endl;
	std:: cout << "Complete" << std::endl;

	contacts[i].setFirstname(tmp[0]);
	contacts[i].setLastname(tmp[1]);
	contacts[i].setNickname(tmp[2]);
	contacts[i].setPhonenumber(tmp[3]);
	contacts[i].setDarkestsecret(tmp[4]);
	i++;

	return ;
}

void	choice_show(std::string str)
{
	if (str.length() > 9)
		std::cout << str.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << str << "|";
}

void	PhoneBook::print_contact(int i)
{
	if (contacts[i].getFirstname()[0])
	{
		std::cout << contacts[i].getFirstname() << std::endl
				<< contacts[i].getLastname() << std::endl
				<< contacts[i].getNickname() << std::endl
				<< contacts[i].getPhonenumber() << std::endl
				<< contacts[i].getDarkestsecret() << std::endl;
	}
	else
		std::cout << "This number doesn't exist\n";
}

void	PhoneBook::search_contact()
{
	int			index;
	std::string input;
	char 		*ptr;

    index = 0;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].getFirstname()[0])
		{
			std::cout << std::setw(10) << i << "|";
			choice_show(contacts[i].getFirstname());
			choice_show(contacts[i].getLastname());
			choice_show(contacts[i].getPhonenumber());
			std::cout << std::endl;	
		}
	}
	std::cout << "Which index you wanna see" << std::endl;
	getline(std::cin, input);
	if (input.empty())
		return ;
	strtol(input.c_str(), &ptr, 10);
	if(*ptr != '\0')
	{
		std::cout << "Index must be numeric" << std::endl;
		return ;	
	}
	index = std::atoi(input.c_str());
	if (index < 0 || index > 7)
	{
		std::cout << "There is no such index\n";
		return ;
	}
	print_contact(index);
}
