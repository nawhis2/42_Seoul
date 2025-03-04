/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:37:24 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 16:18:01 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, FragTrap
{
private:
	static const unsigned int unit_HP = FragTrap::unit_HP;
	static const unsigned int unit_EP = ScavTrap::unit_EP;
	static const unsigned int unit_DMG = FragTrap::unit_DMG;
	
	std::string		name;
	DiamondTrap();

public:
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap& operator=(const DiamondTrap &copy);
	~DiamondTrap();
	
	virtual void attack(const std::string& target);	
	void whoAmI( void );
	void display_stat( void );
	void set_Attack_damage(const unsigned int amount);
	unsigned int	get_Attack_damage( void );
};


#endif
