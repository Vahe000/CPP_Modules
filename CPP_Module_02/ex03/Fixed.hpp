/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:17:48 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/04 22:17:51 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixed_point;
		static const int frac_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int other);
		Fixed(const float other);
		~Fixed();
		
	void	setRawBits(int const raw);
	int		getRawBits() const;
	float	toFloat(void) const;
	int		toInt(void) const;
	
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;
	bool operator<(const Fixed& rhs) const;
	bool operator>(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;

	Fixed &operator=(const Fixed& rhs);
	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;

	Fixed &operator++(void);
	Fixed &operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& max(Fixed &a, Fixed &b);
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a,const Fixed &b);
	static const Fixed& min(const Fixed &a,const Fixed &b);
	
};

std::ostream &operator<<(std::ostream &ostream,const Fixed &copy);

#endif
