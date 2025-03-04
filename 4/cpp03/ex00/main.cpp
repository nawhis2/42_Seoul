/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:12:26 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 14:28:33 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("A");
	ClapTrap b("B");


	a.set_Attack_damage(3);
	b.set_Attack_damage(5);

	a.attack("B");
	b.takeDamage(a.get_Attack_damage());
	b.attack("A");
	a.takeDamage(b.get_Attack_damage());

	a.beRepaired(2);
	b.attack("A");
	a.takeDamage(b.get_Attack_damage());
	b.attack("A");
	a.takeDamage(b.get_Attack_damage());

	a.display_stat();
	b.display_stat();
}