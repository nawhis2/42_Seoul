/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:41:48 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/07 16:00:36 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

std::ostream& operator<<(std::ostream& os, const AForm& form);

int main()
{
	// AForm *scf = new ShrubberyCreationForm("hi");
	AForm *rrf = new RobotomyRequestForm("zz");
	AForm *ppf = new PresidentialPardonForm("gg");
	
	try
	{
		// Bureaucrat A("a", 150);
		// scf->beSigned(A);
		// // scf->execute(A);
		// A.executeForm(*scf);
		// delete scf;

		Bureaucrat B("b", 50);
		rrf->beSigned(B);
		// rrf->execute(B);
		B.executeForm(*rrf);
		delete rrf;

		Bureaucrat C("c", 5);
		ppf->beSigned(C);
		// ppf->execute(C);
		C.executeForm(*ppf);
		delete ppf;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		// delete scf;
		delete rrf;
		delete ppf;
	}
	
	return (0);
}