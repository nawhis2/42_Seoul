/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:27:25 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/06 20:31:38 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << &copy << " Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &copy)
{	
	std::cout << &copy << " Intern copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}
	
AForm *Intern::makeForm(const std::string &name, std::string target)
{
	AForm *f = 0;
	std::string type[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i;
	for (i = 0; i < 4 && type[i] != name; i++) {}
	switch(i)
	{
		case ShrubberyCreationForm:
			f = new class::ShrubberyCreationForm(target);
			break;
		case RobotomyRequestForm:
			f = new class::RobotomyRequestForm(target);
			break;
		case PresidentialPardonForm:
			f = new class::PresidentialPardonForm(target);
			break;
		default:
			break;
	}
	std::cout << "Intern creates " << name << ": " << f << std::endl;
	return (f);
}