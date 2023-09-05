/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:27:50 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/28 18:02:54 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
    Zombie  data("Zombie 1");
    Zombie *date;
    
    data.announce();
    date = newZombie("Zombie 2");
    date->announce();
    randomChump("Zombie 3");
    delete  date;
    return(0);
}