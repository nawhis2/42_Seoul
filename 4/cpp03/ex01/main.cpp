/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:12:26 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/19 15:57:50 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("A");
	ScavTrap b("B");


	a.set_Attack_damage(30);
	b.set_Attack_damage(50);

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

	a.guardGate();
	b.guardGate();
}