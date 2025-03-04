/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:10:48 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/10 17:17:18 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string address : " << &str << std::endl;
	std::cout << "strPTR address : " << stringPTR << std::endl;
	std::cout << "strREF address : " << &stringREF << std::endl;

	std::cout << "string value : " << str << std::endl;
	std::cout << "strPTR value : " << str << std::endl;
	std::cout << "strREF value : " << str << std::endl;
}