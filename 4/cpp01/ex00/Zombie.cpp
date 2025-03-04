/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:59:24 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/15 10:25:07 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str)
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
