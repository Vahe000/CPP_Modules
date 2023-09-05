/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:18:10 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/10 12:35:11 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <cmath>
#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(const Point& other);
	Point(const Fixed a, const Fixed b);
    Point(const Fixed a);
	Point &operator=(const Point& rhs);
	~Point();
	
	float getX();
	float getY();
private:
	const Fixed _x;
	const Fixed _y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif