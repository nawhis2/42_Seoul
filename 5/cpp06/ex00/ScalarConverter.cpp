/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:58:27 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/14 11:48:26 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
	std::cout << "ScalarConverter copy constructor" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	std::cout << "ScalarConverter assignment operator overloading" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor " << std::endl;	
}

// ------------------------------------------------------------------------------------

int checkType(const std::string &data)
{
	std::stringstream ss;
	ss << data;

	double test_fail;
	ss >> test_fail;
	
	if (data.at(data.size() - 1) == 'f')
		return (4);	// float
	else if (data.size() == 1 && !isdigit(data[0]))
		return (1);	// char
	else if ((!ss.fail() && data.find('.') != std::string::npos) || (test_fail < INT_MIN || test_fail > INT_MAX))
		return (3);	// double
	else if (ss.fail() || ss.peek() != EOF)
		return (5);	// not a number (string, ...etc)
	else
		return (2); // int
}

void ScalarConverter::convert(const std::string &data)
{
	std::stringstream ss;
	
	double d;
	char c;
	int i;
	float f;
	
	switch (checkType(data))
	{
		case 1:
		{
			ss.str(data);	
			if (data == " ")
				c = ' ';
			else if (data == "\n")
				c = '\n';
			else
				ss >> c;
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			std::cout << std::fixed << std::setprecision(1);
			break;
		}
		case 2:
		{
			ss.str(data);
			ss >> i;
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			std::cout << std::fixed << std::setprecision(1);
			break;
		}
		case 3:
		{
			ss.str(data);
			ss >> d;
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			if (d == static_cast<int>(d))
				std::cout << std::fixed << std::setprecision(1);
			break;
		}
		case 4: 
		{
			std::string tmp = data;
			tmp.at(tmp.size() - 1) = '\0';
			ss.str(tmp);
			ss >> f;
			if (!ss.fail())
			{
				c = static_cast<char>(f);
				i = static_cast<int>(f);
				d = static_cast<double>(f);
				if (f == static_cast<int>(f))
					std::cout << std::fixed << std::setprecision(1);
				break;
			}
		}
		case 5:
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
	}
	// char
	{
		if (d > CHAR_MAX || d < CHAR_MIN)
			std::cout << "char: impossible" << std::endl;
		else if (data == " " || data == "\n" || isprint(c))
			std::cout << "char: \'" << c << "\'"<< std::endl;
		else
			std::cout << "char: Non_displayable" << std::endl;
	}
	
	// int
	{
		if (d > INT_MAX || d < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
	}

	// float
	{
		if (f != d)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << f << 'f' << std::endl;
	}
	std::cout << "double: " << d << std::endl;
}