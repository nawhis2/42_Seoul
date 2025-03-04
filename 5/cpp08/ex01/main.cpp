/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:17:40 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/31 16:02:42 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// void check()
// {
// 	system("leaks ex01");
// }

int main()
{
	// atexit(check);
	Span sp = Span(5);

	sp.addNumber(6);
	
	// try
	// {
	// 	std::cout << sp.shortestSpan() << std::endl;
	// 	std::cout << sp.longestSpan() << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	// try
	// {
	// 	sp.addNumber(88);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	
	Span container_sp(10000);
	std::vector<int> test_v;
	for (int i = 0 ; i < 10000; i++)
	{
		test_v.push_back(i + 1);
	}
	container_sp.addNumber(test_v);
	std::cout << container_sp.shortestSpan() << std::endl;
	std::cout << container_sp.longestSpan() << std::endl;

	return 0;
}