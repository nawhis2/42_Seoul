/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:41:59 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/30 18:12:49 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure &copy)
{
	this->type = copy.type;
}

Cure& Cure::operator=(const Cure &copy)
{
	if (this->type != copy.type)
		std::cout << "copy's type is not same. It doesn't make sense." << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure material destroyed" << std::endl;
}


Cure* Cure::clone() const
{
	Cure *cl = new Cure;
	return (cl);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}