/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:09:57 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/17 12:43:24 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// #include <limits>

int main( void )
{
	Fixed 		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const p( 42.422f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "p is " << p << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "p is " << p.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	Fixed	i(8388607); // fixed number max int 0- 01- 1- 1-
	std::cout << "i is " << i << std::endl;
	std::cout << "i is " << i.toInt() << " as integer" << std::endl;
	std::cout << "i is " << i.toFloat() << " as float" << std::endl;

	Fixed	h(8388608);	// fixed number min (overflow) 0- 10- 0- 0-
	std::cout << "h is " << h << std::endl;
	std::cout << "h is " << h.toInt() << " as integer" << std::endl;
	std::cout << "h is " << h.toFloat() << " as float" << std::endl;


	// std::cout << std::numeric_limits<float>::max() << std::endl;
	// std::cout << std::numeric_limits<float>::lowest() << std::endl;
	
	// Fixed	j(std::numeric_limits<float>::max());
	// std::cout << "j is " << j << std::endl;
	// std::cout << "j is " << j.toInt() << " as integer" << std::endl;
	// std::cout << "j is " << j.toFloat() << " as float" << std::endl;

	// Fixed	k(std::numeric_limits<float>::lowest());
	// std::cout << "k is " << k << std::endl;
	// std::cout << "k is " << k.toInt() << " as integer" << std::endl;
	// std::cout << "k is " << k.toFloat() << " as float" << std::endl;

	return 0;
}