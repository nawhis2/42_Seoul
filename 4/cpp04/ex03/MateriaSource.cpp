/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:59:07 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/02 13:19:45 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	nums = 0;
	memset(this->slot, 0, sizeof(AMateria *) * 4);
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	AMateria *tmp;
	this->nums = copy.nums;

	for (int i = 0 ; i < copy.nums ; i++)
	{
		if (copy.slot[i]->getType() == "Ice")
			tmp = new Ice;
		else if (copy.slot[i]->getType() == "Cure")
			tmp = new Cure;
		this->slot[i] = tmp;
	}	
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	AMateria *tmp;
	this->nums = copy.nums;
	for (int i = 0 ; i < copy.nums ; i++)
	{
		if (copy.slot[i]->getType() == "Ice")
			tmp = new Ice;
		else if (copy.slot[i]->getType() == "Cure")
			tmp = new Cure;
		this->slot[i] = tmp;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->slot[i])
			delete (this->slot[i]);
	std::cout << "MateriaSource destroyed" << std::endl;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0 ; i < 4; i++)
	{
		if (!this->slot[i])
		{
			this->slot[i] = materia;
			std::cout << "learn " << materia->getType() << " complete" << std::endl;
			return ;
		}
	}
	std::cout << "Cannot Learn more than 4 materia" << std::endl;
	delete (materia);
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *ret;
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] && this->slot[i]->getType() == type)
		{
			ret = this->slot[i];
			this->slot[i] = 0;
			return (ret);
		}
	}
	return (0);
}