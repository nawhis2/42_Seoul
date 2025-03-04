/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:41:37 by sihwan            #+#    #+#             */
/*   Updated: 2024/05/07 12:43:10 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: name("default form"), isSigned(false), grade_toSign(150), grade_toExec(150)
{
	std::cout << "form default constructor called" << std::endl;
}

Form::Form(std::string name, int grade_toSign, int grade_toExec)
	: name(name), isSigned(false), grade_toSign(grade_toSign), grade_toExec(grade_toExec)
{
	if (grade_toSign > 150 || grade_toExec > 150)
		throw Form::GradeTooLowException();
	else if (grade_toSign < 1 || grade_toExec < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form constructor called" << std::endl;
}
	
Form::Form(const Form &copy)
	:name(copy.getName()), isSigned(copy.getisSigned()), grade_toSign(copy.get_grade_toSign()), grade_toExec(copy.get_grade_toExec())
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << copy.getName() <<" cannot change its name by assignment operator" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return (this->name);
}

bool		Form::getisSigned() const
{
	return (this->isSigned);
}

int			Form::get_grade_toSign() const
{
	return (this->grade_toSign);
}

int			Form::get_grade_toExec() const
{
	return (this->grade_toExec);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	std::cout << std::boolalpha;
	os << "* name: " << form.getName() << "\n" 
	<< "* isSigned: " << form.getisSigned() << "\n" 
	<< "* grade for sign: " << form.get_grade_toSign() << "\n" 
	<< "* grade for exec: " << form.get_grade_toExec();
	return (os);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (this->getisSigned())
	{
		throw Form::AlreadySignedException();
	}
	if (this->get_grade_toSign() < b.getGrade())
	{
		throw Form::GradeTooLowException();
	}
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{ 
	return "[Exception] The grade is too high\n";
}

const char* Form::GradeTooLowException::what() const throw()
{ 
	return "[Exception] The grade is too low\n";
}

const char* Form::NotSignedException::what() const throw()
{
	return "[Exception] The form is not signed yet\n";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "[Exception] This Form is already signed\n";
}
