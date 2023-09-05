/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:26:28 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/27 15:55:02 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename x>
void	print_foo(x la)
{
	std::cout << la << " ";
}

template <typename x, typename len>
void	iter(x* p, len l, void (*foo) x&))
{
	for (len i = 0; i < l; i++)
		foo(p[i]);
}

template <typename x, typename len, typename U>
void	iter(x* p, len l, void (*foo)(const U&))
{
	for (len i = 0; i < l; i++)
		foo(p[i]);
}

#endif