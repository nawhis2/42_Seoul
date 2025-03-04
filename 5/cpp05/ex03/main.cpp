/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:41:48 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/07 16:03:22 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::ostream& operator<<(std::ostream& os, const AForm& form);

int main()
{
	Intern someRandomIntern;
	AForm *rrf = 0;
	AForm *scf = 0;
	AForm *ppf = 0;
	Bureaucrat tester("testman", 3);
	
	try
	{
		scf = someRandomIntern.makeForm("ShrubberyCreationForm", "Aender");
		scf->beSigned(tester);
		tester.executeForm(*scf);
		delete scf;

		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
		rrf->beSigned(tester);
		tester.executeForm(*rrf);
		delete rrf;

		ppf = someRandomIntern.makeForm("PresidentialPardonForm", "Cender");
		ppf->beSigned(tester);
		tester.executeForm(*ppf);
		delete ppf;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		delete scf;
		delete rrf;
		delete ppf;
	}
	
	return (0);
}