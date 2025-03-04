/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:44:14 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 16:04:36 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->name = name;
	this->Hit_points = unit_HP;
	this->Energy_points = unit_EP;
	this->Attack_damage = unit_DMG;
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

void FragTrap::set_Attack_damage(const unsigned int amount)
{
	this->Attack_damage = amount;
}

unsigned int	FragTrap::get_Attack_damage( void )
{
	return (this->Attack_damage);
}

void FragTrap::display_stat( void )
{
	std::cout << "NAME: "<< this->name << std::endl;
	std::cout << "HP: " << this->Hit_points << " | EP: " << this->Energy_points << std::endl;
}
