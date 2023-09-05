/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:56:00 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/10 18:37:28 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHACRACTER_HPP
# define CHACRACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria	*droppedinv[4];
		AMateria	*inv[4];
		std::string	_name;
	public:
		Character();
		Character(std::string const & _name);
		Character(const Character& other);
		Character& operator=(const Character& rhs);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif