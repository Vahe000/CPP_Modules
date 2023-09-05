/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:55:27 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/26 17:01:49 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T*				_array;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array<T>& operator=(const Array& rhs);
		~Array();

		unsigned int size() const;
		T& operator[](unsigned int n);
};

#include "Array.tpp"

#endif