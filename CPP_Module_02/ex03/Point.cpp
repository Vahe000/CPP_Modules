/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:18:06 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/11 16:33:37 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
    const_cast<Fixed &>(_x) = 0;
    const_cast<Fixed &>(_y) = 0;
}

Point::Point(const Point &other)
{
    const_cast<Fixed &>(_x) = other._x;
    const_cast<Fixed &>(_y) = other._y;
}

Point::Point(const Fixed a, const Fixed b)
{
    const_cast<Fixed &>(_x) = a;
    const_cast<Fixed &>(_y) = b;
}

Point::Point(const Fixed a)
{
    const_cast<Fixed &>(_x) = a;
    const_cast<Fixed &>(_y) = 0;
}

Point& Point::operator = (const Point& rhs)
{
    if (this != &rhs)
    {
        const_cast<Fixed &>(_x).setRawBits(rhs._x.getRawBits());
        const_cast<Fixed &>(_y).setRawBits(rhs._y.getRawBits());
    }
    return (*this);
}

Point::~Point() {}

float Point::getX()
{
    return (_x.toFloat());
}

float Point::getY()
{
    return (_y.toFloat());
}