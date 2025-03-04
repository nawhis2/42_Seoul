/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:44:17 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 16:18:06 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
	static const unsigned int unit_HP = 100;
	static const unsigned int unit_EP = 100;
	static const unsigned int unit_DMG = 30;

	std::string		name;
	FragTrap();

public:
	FragTrap(const std::string name);
	FragTrap(const FragTrap &copy);
	FragTrap& operator=(const FragTrap &copy);
	~FragTrap();
	void display_stat( void );
	
	virtual void attack(const std::string& target);	
	void highFivesGuys( void );
	void set_Attack_damage(const unsigned int amount);
	unsigned int	get_Attack_damage( void );
};

#endif