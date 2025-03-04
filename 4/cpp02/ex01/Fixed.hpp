/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:10:06 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/17 12:16:15 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					value;
	static const int	frac_bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed& operator=(const Fixed &copy);

	Fixed(const int num);
	Fixed(const float num);
	

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif