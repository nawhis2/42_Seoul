/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:44:14 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/19 16:29:08 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;

	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy.name)
{
	std::cout << "FragTrap copy constructor called" << std::endl;

	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
}
FragTrap& FragTrap::operator=(const FragTrap &copy)
{	
	std::cout << "FragTrap copy assignment operator overloading" << std::endl;
	this->name = copy.name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
	if (this->Hit_points == 0)
	{
		std::cout << this->name << " has no HP" << std::endl;
		return ;
	}
	std::cout << this->name << ": Let's high Fives! " << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->Energy_points == 0)
	{
		std::cout << this->name << "has Not enough Energy" << std::endl;
		return ;
	}
	this->Energy_points--;
	std::cout << "FragTrap " << this->name << 
	" attacks " << target << ", causing " << 
	this->Attack_damage << " points of damage!" << std::endl;

}
