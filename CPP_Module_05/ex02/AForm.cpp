/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:52:19 by vasargsy          #+#    #+#             */
/*   Updated: 2023/06/29 18:25:59 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Julik"), _signed(false), _grade_sign(42), _grade_exec(42){}

AForm::~AForm(){};

AForm::AForm(const std::string& name, const int grade_sign, const int grade_exec)
: _name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (_grade_sign < 1 || _grade_exec < 1)
		throw GradeTooHighException();
	else if (_grade_sign > 150 || _grade_exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
: _name(other._name), _signed(other._signed), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec){}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);
}

const std::string AForm::getFormName() const {return (_name);}
int AForm::getSignGrade() const{return (_grade_sign);}
int AForm::getExecGrade() const{return (_grade_exec);}
bool AForm::getSigned() const{return (_signed);}

std::ostream& operator<<(std::ostream& cout, const AForm& form)
{
    cout << "AForm " << form.getFormName()
		<< "\nSign grade "
		<< form.getSignGrade() << "\nExec grade "
		<< form.getExecGrade();
    return (cout);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _grade_sign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what( void ) const throw()
{
    return ("AForm Exception: Grade too high");
}

const char* AForm::GradeTooLowException::what( void ) const throw()
{
	return ("AForm Exception: Grade too low");
}

const char* AForm::GradeNotSignedException::what( void ) const throw()
{
    return ("Grade is not signed");
}