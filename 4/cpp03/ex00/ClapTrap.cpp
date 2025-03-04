/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:12:17 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 14:29:23 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name )
{
	std::cout << "constructor called" << std::endl;

	this->name = name;
	Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "copy constructor called" << std::endl;

	this->name = copy.name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "copy assignment operator overloading" << std::endl;

	this->name = copy.name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->Energy_points == 0)
	{
		std::cout << this->name << "has Not enough Energy" << std::endl;
		return ;
	}
	this->Energy_points--;
	std::cout << "ClapTrap " << this->name << 
	" attacks " << target << ", causing " << 
	this->Attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Energy_points == 0)
	{
		std::cout << this->name << "has Not enough Energy" << std::endl;
		return ;
	}
	this->Energy_points--;
	std::cout << this->name << " takes Damage " << amount << "points" << std::endl;
	if (this->Hit_points < amount)
	{
		this->Hit_points = 0;
		return ;
	}
	this->Hit_points -= amount;	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energy_points == 0 || this->Hit_points == 0)
	{
		std::cout << this->name << "has Not enough Energy" << std::endl;
		return ;
	}
	this->Energy_points--;
	std::cout << "ClapTrap is repaired " << amount << "points" << std::endl;
	this->Hit_points += amount;
}

void ClapTrap::set_Attack_damage(const unsigned int amount)
{
	this->Attack_damage = amount;
}

unsigned int	ClapTrap::get_Attack_damage( void )
{
	return (this->Attack_damage);
}

void ClapTrap::display_stat( void )
{
	std::cout << "NAME: "<< this->name << std::endl;
	std::cout << "HP: " << this->Hit_points << " | EP: " << this->Energy_points << std::endl;
}
