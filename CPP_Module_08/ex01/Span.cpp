/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:30:02 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/15 16:55:36 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	_N = 0;
}

Span::Span(unsigned int N)
{
	_N = N;
}

Span::Span(const Span& other)
{
	_N = other._N;
	_numbers = other._numbers;
}

Span& Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_N = rhs._N;
		_numbers = rhs._numbers;
	}
	return (*this);
}

Span::~Span(){}

void	Span::addNumber(int new_number)
{
	if (_numbers.size() >= _N)
		throw std::overflow_error("Span is full. Cannot add more numbers.");
	_numbers.push_back(new_number);
}


void Span::addNumbers(const int* begin, const int* end)
{
    size_t count = end - begin;
    if (_numbers.size() + count > _N)
        throw std::overflow_error("Not enough space in Span to add all numbers.");
    _numbers.insert(_numbers.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Cannot find shortest span with less than 2 numbers.");
	std::sort(_numbers.begin(), _numbers.end());
	int minSpan = std::abs(_numbers[1] - _numbers[0]);
    for (size_t i = 1; i < _numbers.size(); ++i)
	{
        // int span = std::abs(_numbers[i] - _numbers[i - 1]);
        if (std::abs(_numbers[i] - _numbers[i - 1]) < minSpan)
            minSpan = std::abs(_numbers[i] - _numbers[i - 1]);
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::logic_error("Cannot find longest span with less than 2 numbers.");\
    std::sort(_numbers.begin(), _numbers.end());
    return (std::abs(_numbers.back() - _numbers.front()));
}