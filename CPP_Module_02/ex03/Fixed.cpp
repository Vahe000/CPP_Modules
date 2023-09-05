/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:17:44 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/04 22:17:54 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_point = 0;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::Fixed(const int b)
{
    fixed_point = b << frac_bits; 
}

Fixed::Fixed(const float b)
{
	fixed_point = roundf(b * (1 << frac_bits));
}

Fixed::~Fixed(){};

Fixed &Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
		fixed_point = rhs.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

void Fixed::setRawBits(int const raw)
{
	fixed_point = raw;
}

int	Fixed::getRawBits() const
{
	return (fixed_point);
}

int Fixed::toInt(void) const
{
	return (fixed_point >> frac_bits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixed_point) / (1 << frac_bits));
}

std::ostream &operator<<(std::ostream &ostream,const Fixed &copy)
{
	ostream << copy.toFloat();
	return (ostream);
}

bool Fixed::operator==(const Fixed& rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed& rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return (false);
}

Fixed& Fixed::operator++(void)
{
    ++fixed_point;
    return (*this);
}

Fixed& Fixed::operator--(void)
{
    --fixed_point;
    return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;

    ++fixed_point;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;

    --fixed_point;
    return (tmp);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed &a,const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a,const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}