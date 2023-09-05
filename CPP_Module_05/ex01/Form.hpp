/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:51:58 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/06 18:37:09 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_grade_exec;
public:
	Form();
	Form(const std::string& name, const int grade_sign, const int grade_exec);
	Form(const Form& other);
	Form& operator=(const Form& rhs);
	~Form();

	const std::string	getFormName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				getSigned() const;

	void				beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& cout, const Form& form);

#endif