/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:41 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/10 11:31:24 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
	{
        Bureaucrat bureaucrat("Zina", 10);
        Form form("Karen", 11, 50);

        bureaucrat.signForm(form);
        std::cout << form << std::endl;


        Bureaucrat bureaucrat2("Vardges", 120);
        Form form2("Garen", 120, 100);

        bureaucrat2.signForm(form2);
        std::cout << form2 << std::endl;
    }
	catch (const std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}