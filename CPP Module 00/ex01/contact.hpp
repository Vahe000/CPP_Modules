/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:53:38 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/03 13:21:11 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();

		std::string	getFirstname();
		std::string	getLastname();
		std::string	getNickname();
		std::string	getPhonenumber();
		std::string	getDarkestsecret();

		void		setFirstname(std::string first_name);
		void		setLastname(std::string last_name);
		void		setNickname(std::string nick_name);
		void		setPhonenumber(std::string phone_number);
		void		setDarkestsecret(std::string darkest_secret);			
};
