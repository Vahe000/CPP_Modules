/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:41:29 by vasargsy          #+#    #+#             */
/*   Updated: 2023/08/12 15:06:10 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

double		ScalarConverter::temp_type = 0;
new_type	ScalarConverter::enum_inf = defaultt;
std::string	ScalarConverter::str_input = "";

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    if (this != &rhs)
        return (*this);
    return (*this);
}

bool    ScalarConverter::is_float_or_double()
{
	if (str_input[0] == '.')
		return false;
    if (str_input.find('.') == std::string::npos)
        return false;
	if (str_input.find('.') != str_input.rfind('.'))
		return false;
	// if (f_index != std::string::npos)
	// {
	// 	if (isdigit(str_input[(f_index - 1)]))
	// 		return false;
	// 	else
	// 		return true;
	// }
    return true;

}

void    ScalarConverter::print_result()
{
    if (std::isprint(static_cast<char>(temp_type)))
        std::cout << "char: \'" << static_cast<char>(temp_type) << "\'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(temp_type) << std::endl;
	if (floor(temp_type) == temp_type)
	{
    	std::cout << "float: " << static_cast<float>(temp_type)<< ".0f" << std::endl;
    	std::cout << "double: " << temp_type << ".0" << std::endl;
	}
	else
	{
    	std::cout << "float: " << static_cast<float>(temp_type)<< "f" << std::endl;
    	std::cout << "double: " << temp_type << std::endl;
	}
}

void    ScalarConverter::print_char()
{
    if (std::isprint(str_input[0]))
        std::cout << "char: \'" <<str_input[0] << "\'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(str_input[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str_input[0])<< ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str_input[0]) << ".0" << std::endl;
}

bool    ScalarConverter::is_inf()
{
    if (str_input == "inf" || str_input == "inff")
    {
        enum_inf = max_inf;
        return true;
    }
    else if (str_input == "-inf" || str_input == "-inff")
    {
        enum_inf = min_inf;
        return true;
    }
    else if (str_input == "nan" || str_input == "nanf")
    {
        enum_inf = nani;
        return true;
    }
    return false;
}

void	ScalarConverter::print_inf()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (enum_inf == max_inf)
	{
		std::cout << "float: inff\n";
		std::cout << "double: inf\n";
	}
	else if (enum_inf == min_inf)
	{
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
	else if (enum_inf == nani)
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
}

bool ScalarConverter::is_number(char *input)
{
	char* endPtr;
    strtod(input, &endPtr);

    if (endPtr != input && (*endPtr == '\0' || input[strlen(input) - 1] == 'f'))
    {
        while (std::isspace(*endPtr))
            ++endPtr;
        if (*endPtr == '\0' || input[strlen(input) - 1] == 'f')
        return true;
            return false;
    }
    return false;
}

void ScalarConverter::convert(char *input)
{
    if (input == NULL)
        return ; 
	str_input = input;
    char        *end = NULL;
    temp_type = strtod(input, &end);

    // if ((temp_type == 0 && input[0] == '0') /* || is_float_or_double() */)
    //     print_result();
    if (temp_type == 0 && input[0] != '0')
	{
		if(str_input.size() > 1)
			std::cerr << "Unknown type\n";
		else
			print_char();
	}
    else if (is_inf())
		print_inf();
	else if (is_number(input))
	{
		std::cout << "dfghj\n";
		print_result();
	}
	else
		std::cerr << "Unknown type\n";
}