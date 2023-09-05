/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:51:17 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/25 16:21:56 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename x>
void	swap(x& a,x& b)
{
	x temp = a;
	a = b;
	b = temp;
}

template <typename x>
x	max(x a,x b)
{
	return (a > b ? a : b);
}

template <typename x>
x	min(x a,x b)
{
	return (a < b ? a : b);
}

#endif