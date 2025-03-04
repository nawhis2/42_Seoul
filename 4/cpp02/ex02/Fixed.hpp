/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:10:06 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/30 11:43:50 by sihkang          ###   ########seoul.kr  */
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

	/* ex02 */
	
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	bool	operator==(const Fixed& a) const;
	bool	operator!=(const Fixed& a) const;
	bool	operator>(const Fixed& a) const;
	bool	operator<(const Fixed& a) const;
	bool	operator>=(const Fixed& a) const;
	bool	operator<=(const Fixed& a) const;

	Fixed	operator+(const Fixed& a);
	Fixed	operator-(const Fixed& a);
	Fixed	operator*(const Fixed& a);
	Fixed	operator/(const Fixed& a);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif