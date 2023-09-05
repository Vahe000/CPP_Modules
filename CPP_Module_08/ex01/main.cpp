/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:29:59 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/28 20:33:48 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

// int main() {
//     try
// 	{
// 		Span span(10000);

//     	int arr[10000];
// 		for (int i = 0; i < 10000; ++i)
//             arr[i] = i + 1;

//         span.addNumbers(arr, arr + 10000);

//         std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
//         std::cout << "Longest Span: " << span.longestSpan() << std::endl;
//     }
// 	catch (const std::exception& e)
// 	{
// 		std::cout << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }