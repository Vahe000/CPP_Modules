/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:15:39 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/23 20:51:43 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

Base* generate()
{
	int random_int;

	srand(time(NULL));
	random_int = rand();
	if (random_int % 3 == 2)
		return (new A);
	else if (random_int % 3 == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "The actual type of the object is A\n"; 
    else if (dynamic_cast<B*>(p))
        std::cout << "The actual type of the object is B\n"; 
    else if (dynamic_cast<C*>(p))
        std::cout << "The actual type of the object is C\n";
}

void identify(Base& p)
{
	try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "The actual type of the object is A\n"; 
        return ;
    }
    catch (...){}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "The actual type of the object is B\n"; 
        return ;
    }
    catch (...){}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "The actual type of the object is C\n";
        return ;
    }
    catch (...){}
}