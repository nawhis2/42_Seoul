/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:29:55 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/15 11:09:04 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string str )
{
	std::cout << "HumanB created" << std::endl;
	name = str;
	weapon = 0;
}

HumanB::~HumanB( void )
{
	std::cout << this->name << " is destroyed" << std::endl;
}

void	HumanB::setWeapon( Weapon &wp )
{
	weapon = &wp;
}

void	HumanB::attack( void )
{
	if (!weapon)
		std::cout << name << " has no weapon" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}