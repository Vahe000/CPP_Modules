/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:12:01 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/27 13:26:54 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	_size = 0;
	_array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other)
{
	_size = other._size;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
	{
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this != &rhs)
	{
		delete[] _array;
		_size = rhs._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw std::out_of_range("n is a out of range");
	return (_array[n]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}