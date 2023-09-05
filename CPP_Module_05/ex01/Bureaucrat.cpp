/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:46:53 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/03 12:50:22 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Aziz"), _grade(77){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string&>(_name) = rhs._name;
		_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){};

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what( void ) const throw()
{
    return ("Bureaucrat Exception: Grade is high");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw()
{
    return ("Bureaucrat Exception: Grade is Low");
}

std::ostream& operator<<(std::ostream& cout, const Bureaucrat& buro)
{
    cout << buro.getName() << " bureaucrat grade " << buro.getGrade() << std::endl;
    return (cout);
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getFormName() << std::endl;
	}
	catch (const std::exception& e)
	{
			std::cout << _name << " couldn't sign form " << form.getFormName() << " because " << e.what() << std::endl;
    }
}