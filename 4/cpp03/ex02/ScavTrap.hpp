/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihwan <sihwan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:44:17 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/19 16:35:01 by sihwan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();

public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap& operator=(const ScavTrap &copy);
	~ScavTrap();

	virtual void attack(const std::string& target);
	void guardGate();
};

#endif