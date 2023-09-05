/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:19:52 by vasargsy          #+#    #+#             */
/*   Updated: 2023/07/06 18:59:17 by vasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("DEFSchrubbery", 145, 137), _target("DEFSchrubbery"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getFormName(), other.getSignGrade(), other.getExecGrade())
{
	_target = other._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
    {
        _target = rhs._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSigned() == false)
		throw AForm::GradeNotSignedException();
	else if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	std::string	str = _target + "shrubbery";
	std::ofstream file(str);
	file << "                                                            \n"
         << "                                   .         :              \n" 
         << "      .              .              :$     ::               \n"
         << "        ,           ,                ::$  $:                \n"
         << "         :         :                   ::$:.     .,         \n"
         << " .        $:     $:            :        $:.    ,:           \n"
         << "  :       :$:  $$:        ,     $:    :$:    ,$.            \n"
         << "   $:       $:$:         :       $:  :$:   ,$:.             \n"
         << "    :$:      $:        :$:        $ :$:  ,$:.               \n"
         << "     `$:.     :$:     $:.         `:$$:.$:.                 \n"
         << "       `::$.    :$$. $$:        $: :$$:$.                   \n"
         << "         `:$:.  ::bd$:          $:$$:.                      \n"
         << "           `$$:.  ::$.         :$$$:.                       \n"
         << "             `$$.  `:$$.      :$$$:                         \n"
         << "               `$$$. `$$$    :$$$:                          \n"
         << "                 :$$. :$$$  $$$$:                           \n"
         << "                   $$bd$$$bd$$::                            \n"
         << "                     #$$$$$$:::                             \n"
         << "                     $$$$$%:::                              \n"
         << "                     %$$$%(o):                              \n"
         << "                     %$$$o%::(                              \n"
         << "                     %$$$o%:::                              \n"
         << "                     )$$$o%:::                              \n" 
         << "                     %$$(o):::                              \n"
         << "                    .%$$$$%:::                              \n"
         << "                    :%$$$$%:::.                             \n"
         << "                   :%$$$$$::::.                             \n"
         << "                ..:%$$$$$$:::::,..                          \n";
}
