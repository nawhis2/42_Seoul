/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:10:14 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/17 15:45:48 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
/* EX00 */

Fixed::Fixed()
{
	value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (getRawBits() != copy.value)
		this->value = copy.value;
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}


/* EX01 */

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	value = (num * (1 << frac_bits));
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	value = roundf(num * (1 << frac_bits));
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(value) / (1 << frac_bits));
}

int		Fixed::toInt( void ) const
{
	return (value / (1 << frac_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << ((fixed.toFloat()));
	return (os);
}

/* ex02 */

bool	operator==(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() == b.getRawBits());
}

bool	operator!=(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() != b.getRawBits());
}

bool	operator>(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits());
}

bool	operator<(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits());
}

bool	operator>=(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() >= b.getRawBits());
}

bool	operator<=(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() <= b.getRawBits());
}

Fixed	operator+(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() + b.getRawBits());
}

Fixed	operator-(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() - b.getRawBits());
}

Fixed	operator*(const Fixed& a, const Fixed& b)
{
	return (a.toFloat() * b.toFloat());
}

Fixed	operator/(const Fixed& a, const Fixed& b)
{
	if (b.toFloat() == 0)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (0);
	}
	return (a.toFloat() / b.toFloat());	
}

Fixed&	Fixed::operator++()
{
	++(this->value);
	return (*this);
}

Fixed&	Fixed::operator--()
{
	--(this->value);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--(*this);
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
