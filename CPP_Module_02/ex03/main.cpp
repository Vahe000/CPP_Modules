/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:18:00 by vasargsy          #+#    #+#             */
/*   Updated: 2023/05/20 13:13:25 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point p1(1, 1), p2(1, 5), p3(5, 1);
    Point p(1, 3);

    if (bsp(p1, p2, p3, p))
        std::cout << "Point is inside triangle!\n";
    else
        std::cout << "Point isn't inside triangle!\n";
}