/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:50:30 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/15 10:40:30 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );


int main( void )
{
	Zombie*	Horde;
	int N = 5;

	Horde = zombieHorde(N, "sihkang");
	for (int i = 0 ; i < N ; i++)
	{
		Horde[i].announce();
	}
	delete[] Horde;
	return (0);
}