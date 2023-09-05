/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:33:51 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/07 20:30:10 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon*		_weapon_type;
		std::string	_name;	
	public:
		HumanA();
		HumanA(std::string& name, Weapon &_type);
		~HumanA();
	void	attack();
};

#endif