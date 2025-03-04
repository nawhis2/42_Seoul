/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:15:01 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/31 15:48:08 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::list<const int> lst;
	std::vector<int> v;

	for (int i = 0 ; i < 10; i++)
	{
		lst.push_back(i);
		v.push_back(i);
	}
	const std::vector<int> v_const = v;
	std::cout << " * * * Not const * * * \n";
	std::cout << *easyfind(lst, 0) << std::endl;
	std::cout << *easyfind(lst, 5) << std::endl;
	std::cout << *easyfind(lst, 9) << std::endl;
	std::cout << *easyfind(lst, 13) << std::endl;
	std::cout << *easyfind(v, 0) << std::endl;
	std::cout << *easyfind(v, 3) << std::endl;
	std::cout << *easyfind(v, 10) << std::endl;

	std::cout << "\n\n * * * Const * * * \n";
	std::cout << *easyfind(v_const, 0) << std::endl;
	std::cout << *easyfind(v_const, 5) << std::endl;
	std::cout << *easyfind(v_const, 9) << std::endl;
	std::cout << *easyfind(v_const, 13) << std::endl;

	return (0);
}