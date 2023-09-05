/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:59:58 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/27 17:00:19 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    // Test with a vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
	{
        std::vector<int>::iterator it = easyfind<std::vector<int> >(vec, 3);
        std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
        std::cout << "Not found in vector!" << std::endl;
	}

    // Test with a list
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    try
	{
        std::list<int>::iterator it = easyfind<std::list<int> >(lst, 25);
        std::cout << "Found: " << *it << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cout << "Not found in list!" << std::endl;
    }

    return 0;
}