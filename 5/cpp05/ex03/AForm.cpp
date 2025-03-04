/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:41:37 by sihwan            #+#    #+#             */
/*   Updated: 2024/05/07 12:24:45 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: name("default form"), isSigned(false), grade_toSign(150), grade_toExec(150)
{
	std::cout << "Form default constructor called " << std::endl;
}

AForm::AForm(std::string name, int grade_toSign, int grade_toExec)
	: name(name), isSigned(false), grade_toSign(grade_toSign), grade_toExec(grade_toExec)
{
	if (grade_toSign > 150 || grade_toExec > 150)
		throw AForm::GradeTooLowException();
	else if (grade_toSign < 1 || grade_toExec < 1)
		throw AForm::GradeTooHighException();
	std::cout << "AForm constructor called" << std::endl;
}
	
	
AForm::AForm(const AForm &copy)
	:name(copy.getName()), isSigned(copy.getisSigned()), grade_toSign(copy.get_grade_toSign()), grade_toExec(copy.get_grade_toExec())
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << copy.getName() <<" cannot change its name by assignment operator" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return (this->name);
}

bool		AForm::getisSigned() const
{
	return (this->isSigned);
}

int			AForm::get_grade_toSign() const
{
	return (this->grade_toSign);
}

int			AForm::get_grade_toExec() const
{
	return (this->grade_toExec);
}

std::ostream& operator<<(std::ostream& os, const AForm& Aform)
{
	std::cout << std::boolalpha;
	os << "* name: " << Aform.getName() << "\n" 
	<< "* isSigned: " << Aform.getisSigned() << "\n" 
	<< "* grade for sign: " << Aform.get_grade_toSign() << "\n" 
	<< "* grade for exec: " << Aform.get_grade_toExec();
	return (os);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (this->getisSigned())
	{
		throw AForm::AlreadySignedException();
	}
	if (this->get_grade_toSign() < b.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	this->isSigned = true;
}


const char* AForm::GradeTooHighException::what() const throw()
{ 
	return "[Exception] The grade is too high\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{ 
	return "[Exception] The grade is too low\n";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "[Exception] The form is not signed yet\n";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "[Exception] This Form is already signed\n";
}