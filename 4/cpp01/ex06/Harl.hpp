/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:56:53 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/12 22:09:30 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

#define DEBUG_MESSAGE	"DEBUG DEBUG DEBUG"
#define INFO_MESSAGE	"INFO INFO INFO"
#define WARNING_MESSAGE	"WARNING WARNING WARNING"
#define ERROR_MESSAGE	"ERROR ERROR ERROR"
#define INVAL_MESSAGE	"INVAL INVAL INVAL"

enum Level
{
	LEVEL_DEBUG,
	LEVEL_INFO,
	LEVEL_WARNING,
	LEVEL_ERROR,
	LEVEL_INVAL,
};

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	void	invalid( void );

public:
	void	complain( std::string level );
};

#endif