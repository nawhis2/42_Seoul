/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:42:01 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/30 18:05:46 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice &copy)
{
	this->type = copy.type;
}

Ice& Ice::operator=(const Ice &copy)
{
	if (this->type != copy.type)
		std::cout << "copy's type is not same. It doesn't make sense." << std::endl;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice materia destroyed" << std::endl;
}


Ice* Ice::clone() const
{
	Ice *ice = new Ice;
	return (ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}