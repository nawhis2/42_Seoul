/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:56:44 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/12 22:10:14 by sihkang          ###   ########seoul.kr  */
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

	std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int i;
	for (i = 0; i < 4 && levels[i] != level; i++) {}

	switch (i)
	{
		case LEVEL_DEBUG:
			(this->*f[LEVEL_DEBUG])();
		case LEVEL_INFO:
			(this->*f[LEVEL_INFO])();
		case LEVEL_WARNING:
			(this->*f[LEVEL_WARNING])();
		case LEVEL_ERROR:
			(this->*f[LEVEL_ERROR])();
			break;
		default:
			(this->*f[LEVEL_INVAL])();
			break;
	}
}
