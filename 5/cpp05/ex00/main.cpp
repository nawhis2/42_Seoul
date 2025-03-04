/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:41:48 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/07 15:44:05 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat A("a", 2);
		A.decGrade(); // A 1
		Bureaucrat B("b", 150);

		// Bureaucrat E("e", 0);
		// Bureaucrat F("f", 155); // exception!
		std::cout << A.getGrade() << " | " << B.getGrade() << std::endl;

		Bureaucrat C(A); // copy construct
		std::cout << A << B << C << std::endl;

		// while (B.getGrade())
		// {
		// 	std::cout << B << std::endl;
		// 	B.decGrade();
		// 	// B.incGrade();
		// }
		std::cout << "end" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return (0);
}