/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:20:26 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/09 16:23:04 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	std::string	input;

	while (true)
	{
		if (std::cin.eof())
		{
			std::cout << "EXIT by EOF" << std::endl;
			break ;
		}
		std::cin.clear();
		std::cout << "INPUT : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "EXIT by EOF" << std::endl;
			break ;
		}
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
			break;
		else
			std::cout << "TRY \"ADD\", \"SEARCH\", and \"EXIT\"." << std::endl;
	}
	return (0);
}
