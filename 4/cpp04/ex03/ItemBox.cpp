/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItemBox.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:34:37 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/02 13:56:30 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ItemBox.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

ItemBox::ItemBox()
{
	std::cout << "Itembox default constructor called" << std::endl;
	this->head = new (t_node);
	this->head->next = 0;
	this->head->materia = 0;
	this->nums = 0;
}

ItemBox::ItemBox(const ItemBox &copy)
{
	std::cout << "Itembox copy constructor called" << std::endl;
	this->nums = copy.nums;
	this->head = new (t_node);
	
	{
		t_node *l_tmp = this->head;
		t_node *r_tmp = copy.getHead();
		while (r_tmp)
		{
			l_tmp = new t_node;
			if (r_tmp->materia->getType() == "ice")
				l_tmp->materia = new Ice();
			else if (r_tmp->materia->getType() == "Cure")
				l_tmp->materia = new Cure();
			l_tmp = l_tmp->next;
			r_tmp = r_tmp->next;
		}
	}
}

ItemBox& ItemBox::operator=(const ItemBox &copy)
{
	std::cout << "Itembox copy assignment constructor called" << std::endl;
	this->nums = copy.nums;
	// 새 item box로 deep copy
	{
		t_node *r_tmp = copy.getHead();
		while (r_tmp)
		{
			if (r_tmp->next && r_tmp->next->materia->getType() == "ice")
				this->addMateria(new Ice());
			else if (r_tmp->next && r_tmp->next->materia->getType() == "cure")
				this->addMateria(new Cure());
			r_tmp = r_tmp->next;
		}
	}

	return (*this);
}

ItemBox::~ItemBox()
{
	t_node *curr;
	t_node *next;

	curr = this->head;
	while (curr->next)
	{
		next = curr->next;
		delete (curr->materia);
		delete (curr);
		curr = next;
	}
	delete (curr->materia);
	delete (curr);
	std::cout << "Itembox destroyed" << std::endl;
}

int		ItemBox::getNums() const
{
	return (this->nums);
}

t_node*	ItemBox::getHead() const
{
	return (this->head);
}

void	ItemBox::addMateria(AMateria *materia)
{
	t_node *tmp;
	tmp = this->head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new t_node;
	tmp->next->materia = materia;
	tmp->next->next = 0;
	this->nums++;
}