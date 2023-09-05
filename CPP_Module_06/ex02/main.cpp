/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:55:31 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/20 19:03:13 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    //-----------------------Test1------------------------
	
    Base* first = generate();
    Base* second = generate();

    std::cout << "Random type (pointer) => ";
        identify(*first);
    std::cout << "Random type (referance) => ";
        identify(first);
    delete first;

    std::cout << "Random type (pointer) => ";
        identify(*second);
    std::cout << "Random type (referance) => ";
        identify(second);
    delete second;

    //-----------------------Test2----------------------------

    Base* a = new A;
     std::cout << "Will print A => ";
        identify(*a);
    std::cout << "Will print A => ";
        identify(a);
    delete a; 

    Base* b= new B;
     std::cout << "Will print B => ";
        identify(*b);
    std::cout << "Will print B => ";
        identify(b);
    delete b;

    Base* c = new C;
     std::cout << "Will print C => ";
        identify(*c);
    std::cout << "Will print C => ";
        identify(c);
    delete c; 
}