/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:52:17 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/03 14:26:26 by vasargsy         ###   ########.fr       */
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
	
	Fixed& operator=(const Fixed& rhs);
};

std::ostream &operator<<(std::ostream &ostream,const Fixed &copy);

#endif
