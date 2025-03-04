/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:50:30 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/15 10:26:09 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main( void )
{
	Zombie	zb1("Foo");
	Zombie	*zb2 = newZombie( "Bar" );

	zb1.announce();
	zb2->announce();
	randomChump( "sihkang" );
	delete zb2;
	return (0);
}