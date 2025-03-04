/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:37:46 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/02 16:04:38 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name)
{
	std::cout << "Character default constructor called" << std::endl;
	this->name = name;
	memset(this->slot, 0, sizeof(AMateria *) * 4);
	this->itembox = new ItemBox();
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	this->name = copy.name;
	for (int i = 0 ; i < 4; i++)
	{
		if (copy.name == "ice")
			this->slot[i] = new Ice;
		else if (copy.name == "cure")
			this->slot[i] = new Cure;
	}
	this->itembox = new ItemBox();
	this->itembox = copy.itembox;
}

Character& Character::operator=(const Character &copy)
{
	std::cout << "Character copy assignment constructor called" << std::endl;
	this->name = copy.name;
	for (int i = 0 ; i < 4; i++)
	{
		delete this->slot[i];
		this->slot[i] = 0;
		if (copy.slot[i] && copy.slot[i]->getType() == "ice")
			this->slot[i] = new Ice;
		else if (copy.slot[i] && copy.slot[i]->getType() == "cure")
			this->slot[i] = new Cure;
	}
	delete (this->itembox);
	this->itembox = new ItemBox();
	*this->itembox = *copy.itembox;
	return (*this);
}

Character::~Character()
{
	delete (this->itembox);
	for (int i = 0 ; i < 4; i++)
		delete this->slot[i];
	std::cout << "Character destroyed" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "equip error : invalid materia" << std::endl;
		return ;
	}
	for (int i = 0 ; i < 4; i++)
	{
		if (!this->slot[i])
		{
			std::cout << "slot[" << i << "] " << m->getType()  << " is equipped"<< std::endl;
			this->slot[i] = m;
			return ;
		}
	}
	std::cout << "equip error : Cannot equip the materia" << std::endl;
	delete (m);
}

void Character::unequip(int idx)
{
	if (0 > idx || idx > 3)
	{
		std::cout << "unequip error : idx is out of range" << std::endl;
		return ;
	}
	if (slot[idx] == NULL)
	{
		std::cout << "unequip error : slot[" << idx << "]" << " Nothing to unequip" << std::endl;
		return ;
	}
	this->itembox->addMateria(slot[idx]);
	slot[idx] = NULL;
	std::cout << "slot[" << idx << "]" << " unequip complete" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || !slot[idx])
	{
		std::cout << "slot[" << idx << "]" << " Cannot use the materia" << std::endl;
		return ;
	}
	slot[idx]->use(target);
}


void Character::item_status(void)
{
	std::cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << std::endl;
	for (int i = 0 ; i < 4; i++) {
		if (this->slot[i]) {
			std::cout << "slot[" << i << "] " << this->slot[i]->getType() << std::endl;
		}
	}
	
	t_node *tmp;
	tmp = this->itembox->getHead();
	while (tmp->next) {
		std::cout << "* item_box " << tmp->next->materia->getType() << std::endl;
		tmp = tmp->next;
	}	
	std::cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << std::endl;
}