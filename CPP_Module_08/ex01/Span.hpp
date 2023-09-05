/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:30:04 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/28 20:35:48 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_N;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();


		void	addNumber(int new_number);
		int		shortestSpan();
		int		longestSpan();
		
		void addNumbers(const int* begin, const int* end);
};

#endif