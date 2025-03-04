/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:12:26 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 15:34:06 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap a("A");
	DiamondTrap b("B");
	
	a.whoAmI();
	a.display_stat();
	a.attack("B");
	b.takeDamage(a.get_Attack_damage());
}