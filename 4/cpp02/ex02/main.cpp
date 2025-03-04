/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:09:57 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/17 15:41:37 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>
#include <limits>

int main( void ) 
{
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;


	std::cout << " * * * * * my test * * * * * " << std::endl;
	std::cout << Fixed(0) * Fixed(1) << std::endl;
	std::cout << Fixed(100) * Fixed(10000) << std::endl;
	std::cout << Fixed(-123) * Fixed(42) << std::endl;
	std::cout << Fixed(2) * Fixed(21.83647f) << std::endl;
	std::cout << std::endl;

	std::cout << Fixed(0) / Fixed(1) << std::endl;
	std::cout << Fixed(100) / Fixed(10000) << std::endl;
	std::cout << Fixed(-123) / Fixed(42) << std::endl;
	std::cout << Fixed(2) / Fixed(21.83647f) << std::endl;

	std::cout << std::endl;	
	std::cout << Fixed(2.1f) / Fixed(1) << std::endl;
	std::cout << Fixed(2.1f) / Fixed(-1) << std::endl;
	
	std::cout << std::endl;
	std::cout << (Fixed(0) / Fixed(0)) << std::endl;
	std::cout << Fixed(1) / Fixed(0) << std::endl;
	std::cout << Fixed(0) / Fixed(1) << std::endl;
	std::cout << 0.0f / 0.0f << std::endl;
	std::cout << 1.0f / 0.0f << std::endl;
	std::cout << 0.0f / 1.0f << std::endl;
	
	return 0;
}