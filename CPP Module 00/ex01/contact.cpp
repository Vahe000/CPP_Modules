/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:21:46 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/03 17:15:26 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(){}
Contact::~Contact(){}

std::string Contact::getFirstname()
{
    return this->first_name;
}

std::string Contact::getLastname()
{
    return this->last_name;
}

std::string Contact::getNickname()
{
    return this->nickname;
}

std::string Contact::getPhonenumber()
{
    return this->phone_number;
}

std::string Contact::getDarkestsecret()
{
    return this->darkest_secret;
}

void        Contact::setFirstname(std::string first_name)
{
    this->first_name = first_name;
}

void        Contact::setLastname(std::string last_name)
{
    this->last_name = last_name;
}

void        Contact::setPhonenumber(std::string phone_number)
{
    this->phone_number = phone_number;
}

void        Contact::setNickname(std::string nick_name)
{
   this->nickname = nick_name;
}

void        Contact::setDarkestsecret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}
