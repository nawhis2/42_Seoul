/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:58:32 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/14 12:01:00 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int special_case(const std::string &data)
{
	if (data == "nan" || data == "+nan" || data == "-nan") 			return 1;
	else if (data == "nanf" || data == "+nanf" || data == "-nanf")	return 2;
	else if (data == "inf")		return 3;
	else if (data == "+inf")	return 4;
	else if (data == "-inf")	return 5;
	else if (data == "+inff")	return 6;
	else if (data == "-inff")	return 7;
	else if (data == "inff")	return 8;
	else						return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	char *arg = argv[1];

	switch (special_case(arg))
	{
	case 1:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << 'f' << std::endl;
		std::cout << "double: " << arg << std::endl;
		break;
	case 2:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << std::endl;
		std::cout << "double: " << "nan" << std::endl;
		break;
	case 3:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << 'f' << std::endl;
		std::cout << "double: " << arg << std::endl;
		break;
	case 4:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << 'f' << std::endl;
		std::cout << "double: " << arg << std::endl;
		break;
	case 5:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << 'f' << std::endl;
		std::cout << "double: " << arg << std::endl;
		break;
	case 6:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << std::endl;
		std::cout << "double: " << "+inf" << std::endl;
		break;
	case 7:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
		break;
	case 8:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << arg << std::endl;
		std::cout << "double: " << "inf" << std::endl;
		break;
	default:
		ScalarConverter::convert(arg);
		break;
	}
	return (0);
}

/**
 * test case
 * nan nanf inf +inf -inf inff +inff -inff
 * any string
 * 0
 * 2147483647
 * 2147384648
 * -2147483647
 * -2147483648
 * 99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
 * 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
 * 3.14
 * 3.14f
*/