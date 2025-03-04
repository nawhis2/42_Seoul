/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:27:28 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/06 20:30:39 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include <iostream>

enum formType
{
	ShrubberyCreationForm,
	RobotomyRequestForm,
	PresidentialPardonForm
};

class Intern
{
private:
	Intern(const Intern &copy);
	Intern& operator=(const Intern &copy);

public:
	Intern();
	~Intern();
	
	AForm *makeForm(const std::string &name, std::string form);
};

#endif