/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:06:07 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/29 17:52:09 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
	{
		_data_base = rhs._data_base;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

void	BitcoinExchange::dataPars(const std::string& data_str)
{
	int				index;
	std::string		key;
	std::string		value;

	index = data_str.find(',');
	key = data_str.substr(0, index);
	value = data_str.substr(index + 1, (data_str.size() - key.size()));
	_data_base.insert(std::make_pair(key, stringToDouble(value)));
}

void	BitcoinExchange::dataBaseFill()
{
	std::string		data_str;
	std::ifstream	data("data.csv");

	getline(data, data_str);
	while (!data.eof())
	{
		getline(data, data_str);
		if (data_str.empty())
			break ;
		dataPars(data_str);
	}
}

void	BitcoinExchange::inputPars(const std::string& input_str)
{
	size_t		index;
	double		res;
	double		quantity_digit;
	std::string	date;
	std::string	quantity;

	index = input_str.find("|");
	date = input_str.substr(0, index - 1);
	if (index == std::string::npos)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	quantity = input_str.substr(index + 1, (input_str.size() - date.size()));
	quantity_digit = stringToDouble(quantity);
	if (!dateErrors(date) || !quantityErrors(quantity))
		return ;

	for (std::map<std::string, double>::const_iterator it = _data_base.begin(); it != _data_base.end(); ++it)
	{
		if (date >= it->first)
			res = it->second * quantity_digit;
    }
	std::cout << date << " => = " << res << std::endl;
}

void	BitcoinExchange::inputRead(char *input_file)
{
	std::ifstream	input(input_file);
	std::string		input_str;

	getline(input, input_str);
	while (!input.eof())
	{
		getline(input, input_str);
		if (input_str.empty())
			break ;
		inputPars(input_str);
	}	
}

bool BitcoinExchange::containsOnlyNumbers(const std::string& str)
{
    for (std::size_t i = 0; i < str.length(); ++i)
	{
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	BitcoinExchange::yearMonthDayErrors(std::string& year, std::string& month, std::string& day)
{
	size_t		year_digit;
	size_t		month_digit;
	size_t		day_digit;

	year_digit = std::atoi(year.c_str());
	day_digit = std::atoi(day.c_str());
	month_digit = std::atoi(month.c_str());

	if (year.size() != 4 || !containsOnlyNumbers(year) || year_digit < 2009 || year_digit > 2147483647)
	{
		std::cout << "Error: bad year\n";
		return false;
	}
	else if (month.size() != 2 || !containsOnlyNumbers(month) || month_digit < 1 || month_digit > 12)
	{
		std::cout << "Error: bad month\n";
		return false;
	}
	else if (day.size() != 2 || !containsOnlyNumbers(day))
	{
		std::cout << "Error: bad day\n";
		return false;
	}
	if (year_digit == 2009 && month_digit == 1 && day_digit < 2)
		return false;
	size_t daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year_digit) && month_digit == 2)
	{
        return day_digit <= 29;
	}
	else
	{
		if (month_digit  == 2 && day_digit == 29)
			std::cout << "Year is leap\n";
        return day_digit <= daysInMonth[month_digit];
	}
	return true;
}

double BitcoinExchange::stringToDouble(std::string str)
{
    char* endPtr;
    double result = strtod(str.c_str(), &endPtr);

    if (*endPtr != '\0')
	{
        std::cout << "Error: Invalid conversion for string: " << str << std::endl;
        return 0;
    }
    return result;
}

bool	BitcoinExchange::dateErrors(const std::string& date)
{
	size_t		index;
	size_t		r_index;
	std::string	year;
	std::string	month;
	std::string	day;

	index = date.find("-");
	r_index = date.rfind("-");
	if (index == std::string::npos)
	{
		std::cout << "Invalid date\n";
		return false;
	}
	year = date.substr(0, index);
	day = date.substr(r_index + 1, date.size() - r_index - 1);
	month = date.substr(index + 1, date.size() - (day.size() + year.size()) - 2);
	if (!yearMonthDayErrors(year, month, day))
		return false;
	
	return true;
}

bool	BitcoinExchange::quantityErrors(const std::string& quantity)
{
	long		quantity_digit;

	quantity_digit = std::atof(quantity.c_str());
	if (quantity_digit > 1000)
	{
		std::cout << "Error: too large a number.\n";
		return false;
	}
	if (quantity_digit < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return false;
	}
	return true;
}