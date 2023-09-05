/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:05:40 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/07 12:31:15 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern&){}

Intern& Intern::operator=(Intern& op)
{
	if (this != &op)
		return (*this);
	return (*this);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm*		(Intern::*function_pointers[3])(const std::string target) = {&Intern::makePresident, &Intern::makeRobot, &Intern::makeShrubbery};
	std::string forms[3] = {"robotomy request",
							"presidential pardon",
							"shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << " now" << std::endl;
			return ((this->*function_pointers[i])(target));
		}
	}
	std::cout << "Intern can not create a form called " << name << std::endl;
	return (NULL);
}

Intern::~Intern(){}

AForm*	Intern::makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}