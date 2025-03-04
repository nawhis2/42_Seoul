/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:37:20 by sihwan            #+#    #+#             */
/*   Updated: 2024/05/31 18:00:02 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->name = name;
	this->Hit_points = FragTrap::unit_HP;
	this->Energy_points = ScavTrap::unit_EP;
	this->Attack_damage = FragTrap::unit_DMG;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy.name), ScavTrap(copy.name), FragTrap(copy.name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	this->name = copy.name;
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << "Diamond copy assignment operator called" << std::endl;
	
	this->ClapTrap::name = copy.name + "_clap_name";
	this->Hit_points = copy.Hit_points;
	this->Energy_points = copy.Energy_points;
	this->Attack_damage = copy.Attack_damage;

	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "WhoAmI : " << this->name << " from " << this->ClapTrap::name << std::endl;
}


void DiamondTrap::set_Attack_damage(const unsigned int amount)
{
	this->Attack_damage = amount;
}

unsigned int	DiamondTrap::get_Attack_damage( void )
{
	return (this->Attack_damage);
}

void DiamondTrap::display_stat( void )
{
	std::cout << "NAME: "<< this->name << std::endl;
	std::cout << "HP: " << this->Hit_points << " | EP: " << this->Energy_points << std::endl;
}
