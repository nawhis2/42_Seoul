/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:44:17 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 18:28:05 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	static const unsigned int unit_HP = 100;
	static const unsigned int unit_EP = 50;
	static const unsigned int unit_DMG = 20;
	
	std::string		name;
	ScavTrap();

public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap &copy);
	~ScavTrap();
	void display_stat( void );

	virtual void attack(const std::string& target);
	void set_Attack_damage(const unsigned int amount);
	unsigned int	get_Attack_damage( void );
	void guardGate();
};

#endif