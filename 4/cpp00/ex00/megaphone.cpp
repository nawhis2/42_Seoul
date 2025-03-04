/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:11:18 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/02 15:19:39 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			int j = 0;
			while (argv[i][j] != '\0')
			{
				if (islower(argv[i][j]))
					std::cout << (char)toupper(argv[i][j]);
				else
					std::cout << (char)argv[i][j];
				j++;
			}
			std::cout << ' ';
		}
	}
	std::cout << '\n';
	return (0);
}