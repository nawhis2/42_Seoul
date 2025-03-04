/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:29:58 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/15 10:59:52 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon 		*weapon;
	HumanB( void );
	
public:
	HumanB( std::string str );
	~HumanB( void );
	void	setWeapon( Weapon &wp );
	void	attack( void );
	
};

#endif