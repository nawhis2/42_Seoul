/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:44:17 by sihwan            #+#    #+#             */
/*   Updated: 2024/04/22 14:40:02 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	FragTrap();

public:
	FragTrap(const std::string name);
	FragTrap(const FragTrap &copy);
	FragTrap& operator=(const FragTrap &copy);
	~FragTrap();
	
	virtual void attack(const std::string& target);	
	void highFivesGuys( void );
};

#endif