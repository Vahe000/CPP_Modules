/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:41 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/06 19:12:07 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
	
	// Create a ShrubberyCreationForm
	try
	{
		Intern		Intern1;
		AForm* shrubberyForm = Intern1.makeForm("shrubbery creation", "home");
		delete shrubberyForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//Create a RobotomyRequestForm
	try
	{
		Intern		Intern2;
		AForm* robotomyForm = Intern2.makeForm("robotomy request", "Bender");
		delete robotomyForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// Create a PresidentialPardonForm
	try
	{
		Intern		Intern3;
		AForm* presidentialForm = Intern3.makeForm("presidential pardon", "Zaphod Beeblebrox");
		delete presidentialForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// Try to create a non-existent form
	try
	{
		Intern		Intern4;
		AForm* unknownForm = Intern4.makeForm("unknown form", "target");
		delete unknownForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}