/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:44:14 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 14:36:07 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;

	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy.name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;

	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{	
	std::cout << "ScavTrap copy assignment operator overloading" << std::endl;
	this->name = copy.name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate( void )
{
	if (this->Hit_points == 0)
	{
		std::cout << this->name << " cannot transform guardGate mode." << std::endl;
		return ;
	}
	std::cout << this->name << " transforms guardGate mode " << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->Energy_points == 0)
	{
		std::cout << this->name << "has Not enough Energy" << std::endl;
		return ;
	}
	this->Energy_points--;
	std::cout << "ScavTrap " << this->name << 
	" attacks " << target << ", causing " << 
	this->Attack_damage << " points of damage!" << std::endl;

}
