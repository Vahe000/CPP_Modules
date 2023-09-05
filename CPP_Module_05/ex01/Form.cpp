/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:52:19 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/03 12:54:38 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Julik"), _signed(false), _grade_sign(42), _grade_exec(42){}

Form::~Form(){};

Form::Form(const std::string& name, const int grade_sign, const int grade_exec)
: _name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (_grade_sign < 1 || _grade_exec < 1)
		throw GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
: _name(other._name), _signed(other._signed), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec){}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string&>(_name) = rhs._name;
		_signed = rhs._signed;
	}
	return (*this);
}

const std::string Form::getFormName() const {return (_name);}
int Form::getSignGrade() const{return (_grade_sign);}
int Form::getExecGrade() const{return (_grade_exec);}
bool Form::getSigned() const{return (_signed);}

std::ostream& operator<<(std::ostream& cout, const Form& form)
{
    cout << "Form " << form.getFormName()
		<< "\nSign grade "
		<< form.getSignGrade() << "\nExec grade "
		<< form.getExecGrade();
    return (cout);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _grade_sign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what( void ) const throw()
{
    return ("Form Exception: Grade too high");
}

const char* Form::GradeTooLowException::what( void ) const throw()
{
	return ("Form Exception: Grade too low");
}
