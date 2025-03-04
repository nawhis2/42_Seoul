/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:28:51 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/15 11:00:38 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon 		&type;
	HumanA( void );
	
public:
	HumanA(std::string str, Weapon &wp);
	~HumanA( void );
	void	attack( void );
	
};

#endif