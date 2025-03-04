/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:45:48 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/30 13:05:27 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Materia constructed" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Materia destoryed" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Need to Upgrade using for " << target.getName() << std::endl;
}
