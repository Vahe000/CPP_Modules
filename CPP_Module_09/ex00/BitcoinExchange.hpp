/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:06:04 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/14 19:37:36 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream> 
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_data_base;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void	dataPars(const std::string& input_str);
		void	dataBaseFill();
		void	inputRead(char *input_file);
		void	inputPars(const std::string& input_file);
		bool	dateErrors(const std::string& date);
		bool	yearErrors(std::string& year);
		bool	yearMonthDayErrors(std::string& year, std::string& month, std::string& day);
		bool	containsOnlyNumbers(const std::string& str);
		bool	quantityErrors(const std::string& quantity);
		double	stringToDouble(std::string str);
		bool	isLeapYear(int year);
};

#endif