/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:05:50 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/06 15:47:57 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(Intern& rhs);
	~Intern();

	AForm* makeForm(const std::string& name, const std::string& target);
private:
	AForm*	makePresident(const std::string target);
	AForm*	makeRobot(const std::string target);
	AForm*	makeShrubbery(const std::string target);
};


#endif