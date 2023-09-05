/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:51:58 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/04 18:34:36 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_grade_sign;
	const int			_grade_exec;
public:
	AForm();
	AForm(const std::string& name, const int grade_sign, const int grade_exec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& rhs);
	virtual ~AForm();

	const std::string	getFormName() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	bool				getSigned() const;

	void				beSigned(const Bureaucrat& b);
	virtual void		execute(Bureaucrat const & executor) const = 0;	

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
	
	class GradeNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class NotFoundException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& cout, const AForm& form);

#endif