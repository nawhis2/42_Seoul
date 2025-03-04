/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:29:03 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/15 11:01:24 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &wp)
	: name(str), type(wp) 
{
	std::cout << "HumanA created" << std::endl;	
}

HumanA::~HumanA( void )
{
	std::cout << this->name << " is destroyed" << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << name << " attacks with their " 
			<< type.getType() << std::endl;
}