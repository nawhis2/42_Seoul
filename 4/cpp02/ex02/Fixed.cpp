/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:10:14 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/30 11:43:52 by sihkang          ###   ########seoul.kr  */
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

bool	Fixed::operator==(const Fixed& a) const
{
	return (a.getRawBits() == this->getRawBits());
}

bool	Fixed::operator!=(const Fixed& a) const
{
	return (a.getRawBits() != this->getRawBits());
}

bool	Fixed::operator>(const Fixed& a) const
{
	return (this->getRawBits() > a.getRawBits());
}

bool	Fixed::operator<(const Fixed& a) const
{
	return (this->getRawBits() < a.getRawBits());
}

bool	Fixed::operator>=(const Fixed& a) const
{
	return (this->getRawBits() >= a.getRawBits());
}

bool	Fixed::operator<=(const Fixed& a) const
{
	return (this->getRawBits() <= a.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& a)
{
	return (a.getRawBits() + this->getRawBits());
}

Fixed	Fixed::operator-(const Fixed& a)
{
	return (this->getRawBits() - a.getRawBits() );
}

Fixed	Fixed::operator*(const Fixed& a)
{
	return (a.toFloat() * this->toFloat());
}

Fixed	Fixed::operator/(const Fixed& a)
{
	if (a.toFloat() == 0)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (0);
	}
	return (this->toFloat() / a.toFloat());	
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
