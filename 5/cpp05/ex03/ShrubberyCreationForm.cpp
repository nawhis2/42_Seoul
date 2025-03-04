/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:58:56 by sihwan            #+#    #+#             */
/*   Updated: 2024/05/06 20:22:58 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("SCF", SCF_SIGN, SCF_EXEC), target("SCF target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:AForm(target, SCF_SIGN, SCF_EXEC), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	:AForm(copy), target(copy.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	std::cout << copy.getName() <<" cannot change its name by assignment operator" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;	
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getisSigned())
	{
		throw NotSignedException();
	}
	if (this->get_grade_toExec() < executor.getGrade())
	{
		throw GradeTooLowException();
	}
	std::ofstream outfile;
	outfile.open(this->getName() + "_shrubbery");
	if (!outfile)
		return ;
	outfile << "         v\n"
			<< "        >X<\n"
			<< "         A\n"
			<< "        d$b\n"
			<< "      .d\\$$b.\n"
			<< "    .d$i$$\\$$b.\n"
			<< "       d$$@b\n"
			<< "      d\\$$$ib\n"
			<< "    .d$$$\\$$$b\n"
			<< "  .d$$@$$$$\\$$ib.\n"
			<< "      d$$i$$b\n"
			<< "     d\\$$$$@$b\n"
			<< "  .d$@$$\\$$$$$@b.\n"
			<< ".d$$$$i$$$\\$$$$$$b.\n"
			<< "        ###\n"
			<< "        ###\n"
			<< "        ###\n"
 			<< std::endl;
}
