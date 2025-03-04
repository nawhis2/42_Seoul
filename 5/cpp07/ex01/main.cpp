/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:22:47 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/15 15:13:59 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void plusOne(const int &i)
{
	std::cout << "added: " << i + 1 << std::endl;
}

void makeUpper(const char &c)
{
	std::cout << "Upper: " << static_cast<char>(toupper(c)) << std::endl;
}

void howLong(const std::string &str)
{
	std::cout << "element has " << str.size() << " characters." << std::endl;
}

int main()
{
	int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char arr2[11] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
	std::string arr3[3] = {"Hello", "World", "SayHo"};

	iter(arr1, 10, plusOne);
	iter(arr2, 11, makeUpper);
	iter(arr3, 3, howLong);

	/* The third parameter is function template */
	iter(arr1, 10, print);
	iter(arr2, 11, print);
	iter(arr3, 3, print);
}
