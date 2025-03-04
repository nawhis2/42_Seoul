/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:56:44 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/12 22:05:20 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << DEBUG_MESSAGE << std::endl;
}

void	Harl::info( void )
{
	std::cout << INFO_MESSAGE << std::endl;
}

void	Harl::warning( void )
{
	std::cout << WARNING_MESSAGE << std::endl;
}

void	Harl::error( void )
{
	std::cout << ERROR_MESSAGE << std::endl;
}

void	Harl::invalid( void )
{
	std::cout << INVAL_MESSAGE << std::endl;
}

void	Harl::complain( std::string level )
{
	void	(Harl::*f[5])(void) = { &Harl::debug,
									&Harl::info,
									&Harl::warning,
									&Harl::error,
									&Harl::invalid };

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int i;
	for (i = 0; i < 4 && levels[i] != level; i++) {}
	(this->*f[i])();
}
