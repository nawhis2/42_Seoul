/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:59:24 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/10 17:06:49 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	return ;
}

Zombie::Zombie(std::string str)
{
	name = str;
}

Zombie::Zombie(int N, std::string str)
{
	Zombie	*zb_horde;

	zb_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zb_horde[i].name = str;
}

void	Zombie::SetName(std::string str)
{
	name = str;
}

Zombie::~Zombie( void )
{
	std::cout << name << " is destroyed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
