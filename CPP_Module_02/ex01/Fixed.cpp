/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:52:27 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/20 19:08:58 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int b)
{
    std::cout << "Int constructor called\n";
    fixed_point = b << frac_bits;
	std::cout << "fixed_point = " << fixed_point << std::endl;
}

Fixed::Fixed(const float b)
{
    std::cout << "Float constructor called\n";
	fixed_point = roundf(b * (1 << frac_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		fixed_point = rhs.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const raw)
{
	fixed_point = raw;
}

int	Fixed::getRawBits() const
{
	return (fixed_point);
}

int Fixed::toInt(void)const
{
	return (fixed_point >> frac_bits);
}

float Fixed::toFloat(void)const
{
	return (static_cast<float>(fixed_point) / (1 << frac_bits));
}

std::ostream &operator<<(std::ostream &ostream,const Fixed &copy)
{
	ostream << copy.toFloat();
	return (ostream);
}