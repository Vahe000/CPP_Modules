/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Zombie.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:25 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/04 12:34:26 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << "Constructor killed me" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}
