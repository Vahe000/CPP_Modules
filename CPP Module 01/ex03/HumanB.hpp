/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:34:23 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/25 17:35:47 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*_weapon_type;
		std::string	_name;	
	public:
		HumanB();
		HumanB(std ::string name);
		~HumanB();
	void	attack();
	void	setWeapon(Weapon &type);
};

#endif