/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:41 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/10 11:27:40 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
    try
    {
        Bureaucrat b("Lianchik", 149);
        std::cout << b;
        b.decrementGrade();
        std::cout << b ;
        b.incrementGrade();
        std::cout << b ;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}