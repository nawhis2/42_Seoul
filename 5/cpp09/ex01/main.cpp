/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:40:52 by sihkang           #+#    #+#             */
/*   Updated: 2024/07/13 15:42:20 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error1\n";
		return (1);
	}
	std::stack<int> st;
	std::stringstream ss;
	ss << argv[1];
	while (42)
	{
		char c = 0;
		ss >> c;
		
		if (isdigit(c))
			RPN::push_data(st, c - '0');
		else if ((c == '+' || c == '-' || c == '/' || c == '*') && st.size() >= 2)
		{
			int num1, num2;
			num1 = RPN::pop_data(st);
			num2 = RPN::pop_data(st);
			if (c == '+')
				RPN::push_data(st, num2 + num1);
			else if (c == '-')
				RPN::push_data(st, num2 - num1);
			else if (c == '/')
			{
				if (num1 == 0)
					break;
				RPN::push_data(st, num2 / num1);
			}
			else if (c == '*')
				RPN::push_data(st, num2 * num1);
		}
		else if (c == 0)
			break;
		else
		{
			std::cout << "Error2\n";
			return (1);
		}
	}
	if (st.size() == 1)
		std::cout << RPN::pop_data(st) << std::endl;
	else
		std::cout << "Input Error\n";
	return (0);
}