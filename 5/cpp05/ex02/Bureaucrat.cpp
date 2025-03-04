/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:41:53 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/07 12:42:48 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( void ) : name("Default")
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (this->grade < 1)
		throw GradeTooHighException();
	else if (this->grade > 150)
		throw GradeTooLowException();
	std::cout << this->name << ": Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.getName()), grade(copy.getGrade())
{
	if (this->grade < 1)
		throw GradeTooHighException();
	else if (this->grade > 150)
		throw GradeTooLowException();
	std::cout << this->name << ": Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << copy.getName() <<" cannot change its name by assignment operator" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << this->name << ": Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << "# " << (bureaucrat.getName()) << ", bureaucrat grade " << (bureaucrat.getGrade()) << std::endl;
	return (os);
}

Bureaucrat&	Bureaucrat::incGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	++(this->grade);
	std::cout << this->getName() << " level down to " << this->getGrade() << std::endl;
	return (*this);
}

Bureaucrat&	Bureaucrat::decGrade()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	--(this->grade);
	std::cout << this->getName() << " level up to " << this->getGrade() << std::endl;
	return (*this);
}

void	Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
	std::cout << this->getName() << " signed [" << form.getName() << "]" << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
	std::cout << this->name << " executed " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{ 
	return "[Exception] The grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{ 
	return "[Exception] The grade is too low\n";
}