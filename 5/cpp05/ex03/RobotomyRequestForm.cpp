/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:05 by sihwan            #+#    #+#             */
/*   Updated: 2024/05/06 20:22:39 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("RRF", RRF_SIGN, RRF_EXEC), target("RRF target")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:AForm(target, RRF_SIGN, RRF_EXEC), target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	:AForm(copy), target(copy.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << copy.getName() << " cannot change its name by assignment operator" << std::endl;
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getisSigned())
	{
		throw NotSignedException();
	}
	if (this->get_grade_toExec() < executor.getGrade())
	{
		throw GradeTooLowException();
	}
	srand(static_cast<unsigned int>(time(0)));
	if (rand() % 2)
		std::cout << "RobotomyRequestForm [" << this->getName() << "]: drilling... drilling..." << std::endl;
	else
		std::cout << "RobotomyRequestForm [" << this->getName() << "]: ..." << std::endl;
}
