/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:41 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/06 15:16:27 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat highGradeBureaucrat("John", 1);
        Bureaucrat lowGradeBureaucrat("Bob", 150);

        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Target");
        PresidentialPardonForm pardonForm("Target");

        highGradeBureaucrat.signForm(shrubberyForm);
        highGradeBureaucrat.executeForm(shrubberyForm);

        lowGradeBureaucrat.signForm(robotomyForm);
        lowGradeBureaucrat.executeForm(robotomyForm);

        highGradeBureaucrat.signForm(robotomyForm);
        highGradeBureaucrat.executeForm(robotomyForm);

        highGradeBureaucrat.signForm(pardonForm);
        highGradeBureaucrat.executeForm(pardonForm);

    }
	catch (const std::exception& e)
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}