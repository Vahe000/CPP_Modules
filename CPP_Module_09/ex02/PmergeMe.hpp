/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:44:49 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/15 18:57:17 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <list>
#include <deque>
#include <iomanip>
#include <climits>

const int LIMIT = 5;

void sortSequence(std::vector<int>& sequence, const std::string& container1, const std::string& container2);

template<typename It>
void insertionSort(It begin, It end)
{
	It it1, it2;

	for (it1 = begin + 1; it1 <= end; ++it1)
	{
		int key = *it1;
		it2 = it1;
		while (it2 > begin && key < *(it2 - 1))
		{
			*it2 = *(it2 - 1);
			--it2;
		}
		*it2 = key;
	}
}

template <typename T>
void mergeSort(T& c, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	T	L(n1);
	T	R(n2);
	
	for (int i = 0; i < n1; ++i)
		L[i] = c[left + i];
	
	for (int i = 0; i < n2; ++i)
		R[i] = c[mid + i + 1];
	
	int i = 0, j = 0, k = left;
	
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
			c[k++] = L[i++];
		else
			c[k++] = R[j++];
	}
	
	while (i < n1)
		c[k++] = L[i++];
	
	while (j < n2)
		c[k++] = R[j++];
}

template <typename T>
void	mergeInsertionSort(T& c, int left, int right)
{
	if (right - left <= LIMIT)
	{
		insertionSort(c.begin() + left, c.begin() + right);
	}
	else
	{
		int mid = left + (right - left) / 2;
		mergeInsertionSort(c, left, mid);
		mergeInsertionSort(c, mid + 1, right);
		mergeSort(c, left, mid, right);
	}
}


#endif