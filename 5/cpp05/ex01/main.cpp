/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:41:48 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/07 15:50:03 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

std::ostream& operator<<(std::ostream& os, const Form& form);

int main()
{
	try
	{
		Form form1("form1", 137, 127);
		// Form form2("form2", 0, 127); // too high
		// Form form3("form3", 137, 155); // too low
		Bureaucrat A("a", 140);
		A.signForm(form1);
		// form1.beSigned(A);
		A.signForm(form1);
		std::cout << form1 << "\n" << A <<std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return (0);
}