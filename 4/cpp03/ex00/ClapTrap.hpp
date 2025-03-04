/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:12:24 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 14:26:54 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string	name;
	unsigned int	Hit_points;
	unsigned int Energy_points;
	unsigned int Attack_damage;
	ClapTrap( void );

public:
	ClapTrap( std::string name );
	ClapTrap(const ClapTrap &copy);
	ClapTrap& operator=(const ClapTrap &copy);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	// my own
	void 			set_Attack_damage(const unsigned int amount);
	unsigned int	get_Attack_damage( void );
	void 			display_stat( void );

};


#endif