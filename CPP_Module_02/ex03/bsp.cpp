/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:17:39 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/12 16:11:41 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float area_ = 0.5 * abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)));
    return area_;
}

bool bsp(Point p1, Point p2, Point p3, Point p)
{
    float totalArea = area(p1.getX(), p1.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY());
    
    float area1 = area(p.getX(), p.getY(), p1.getX(), p1.getY(), p2.getX(), p2.getY());
    float area2 = area(p.getX(), p.getY(), p2.getX(), p2.getY(), p3.getX(), p3.getY());
    float area3 = area(p.getX(), p.getY(), p3.getX(), p3.getY(), p1.getX(), p1.getY());

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
    return (totalArea == area1 + area2 + area3);
}
