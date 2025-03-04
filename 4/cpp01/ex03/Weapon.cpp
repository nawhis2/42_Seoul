/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:28:44 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/15 11:01:29 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon( void )
{
	std::cout << "Weapon created" << std::endl;
	type = "Hands";
}

Weapon::Weapon( std::string type )
{
	std::cout << "Weapon created" << std::endl;
	this->type = type;
}

Weapon::~Weapon( void )
{
	std::cout << this->type << " is destroyed" << std::endl;
}

const std::string &Weapon::getType( void )
{	
	return (this->type);
}

void Weapon::setType( std::string type )
{
	this->type = type;
}
