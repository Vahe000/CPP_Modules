/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:47:55 by vasargsy          #+#    #+#             */
/*   Updated: 2023/04/29 19:32:30 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace
{
private:
	std::string	_fileName;
	std::string _s1;
	std::string _s2;
public:
	Replace();
	Replace(std::string file_name, std::string s1, std::string s2);
	~Replace();
	void	replace_string(void);
};

#endif