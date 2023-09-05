/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:37:24 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/04 14:51:31 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./phonebook.hpp"

int main()
{
	std::string	s;
	PhoneBook	book;
	while(true)
	{
        std::cout << "Please choose from this commands: ADD, SEARCH or EXIT" << std::endl;
		getline(std::cin, s);
        if (std::cin.eof())
            return (1);
		if (s[0])
		{
			if (s.compare("ADD") == 0)
				book.init_data();
			else if (s.compare("SEARCH") == 0)
            {
                if (std::cin.eof())
                    break ;
				book.search_contact();
            }
			else if (s.compare("EXIT") == 0)
				break ;
			else
				std::cout << "Wrong command" << std::endl;		
		}
    }
	return (0);
}