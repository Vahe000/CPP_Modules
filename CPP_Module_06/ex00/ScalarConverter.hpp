/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:41:32 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/20 17:36:00 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
// #include <ctype.h> 

enum new_type
{
    min_inf = 1,
    max_inf = 2,
    nani = 3,
    defaultt = 4
};

class ScalarConverter
{
private:
    static new_type		enum_inf;
    static double		temp_type;
	static std::string	str_input;
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& rhs);
    ~ScalarConverter();
public:
    static void convert(char* input);
private:
    static bool is_float_or_double();
    static void print_result();
    static bool is_inf();
	static void print_inf();
	static void print_char();
	static bool is_number(char* temp_type);
};

#endif