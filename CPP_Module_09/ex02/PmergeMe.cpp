/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:44:51 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/15 19:21:24 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void sortSequence(std::vector<int>& sequence, const std::string& container1, const std::string& container2)
{
    std::deque<int> dequeContainer(sequence.begin(), sequence.end());
	
	std::cout << "Before:";
	for (size_t i = 0; i < sequence.size(); ++i)
	{
		std::cout << " " << sequence[i];
	}
    std::cout << std::endl;

    clock_t startTime1 = clock();
    mergeInsertionSort(sequence, 0, sequence.size() - 1);
    clock_t endTime1 = clock();
    double time1 = static_cast<double>(endTime1 - startTime1) / CLOCKS_PER_SEC;

    clock_t startTime2 = clock();
    mergeInsertionSort(dequeContainer, 0, dequeContainer.size() - 1);
    clock_t endTime2 = clock();
    double time2 = static_cast<double>(endTime2 - startTime2) / CLOCKS_PER_SEC;

    std::cout << "After:";
    if (container1 == "vector")
	{
        for (std::vector<int>::iterator it = sequence.begin(); it != sequence.end(); ++it)
		{
            std::cout << " " << *it;
        }
    }
	else if (container1 == "deque")
	{
        for (std::deque<int>::iterator it = dequeContainer.begin(); it != dequeContainer.end(); ++it)
		{
            std::cout << " " << *it;
        }
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << sequence.size() << " elements with std::" << container1 << ": "
              << std::fixed << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << sequence.size() << " elements with std::" << container2 << ": "
              << std::fixed << time2 << " us" << std::endl;
}