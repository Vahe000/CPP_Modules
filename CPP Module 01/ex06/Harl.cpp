/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:35:15 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/28 19:11:07 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};
Harl::~Harl(){};

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl 
			<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			<< std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl 
			<< "I cannot believe adding extra bacon costs more money. You didn’t put"
			<<	"enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			<< std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl 
			<< "I think I deserve to have some extra bacon for free. I’ve been coming for"
			<< "years whereas you started working here since last month."
			<< std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl 
			<< "This is unacceptable! I want to speak to the manager now."
			<< std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*function_pointers[4]) () = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	for ( ; i < 4 && level.compare(levels[i]); ++i);
	if (i == 4)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	switch (i)
	{
	case 0:
		(this->*function_pointers[0]) ();
	case 1:
		(this->*function_pointers[1]) ();
	case 2:
		(this->*function_pointers[2]) ();
	case 3:
		(this->*function_pointers[3]) ();
	default:
		break;
	}
}