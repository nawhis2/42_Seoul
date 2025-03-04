/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:07:44 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/15 14:06:20 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	char *f = new char[100];
	char *e = new char[100];
	e[0] = 'h';
	e[1] = 'e';
	e[2] = 'l';
	e[3] = 'l';
	e[4] = 'o';
	e[5] = 'z';
	e[6] = 'z';
	e[7] = 'z';
	e[8] = 'z';
	e[9] = 'z';

	f[0] = 'w';
	f[1] = 'o';
	f[2] = 'r';
	f[3] = 'l';
	f[4] = 'd';

	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	
	int *z = new int[10];
	int *zz = new int [11];
	::swap(z, zz);
	std::cout << "z = " << z << ", zz = " << zz << std::endl;
	std::cout << "min : " << ::min( z, zz) << std::endl;
	std::cout << "max : " << ::max(z,zz) << std::endl;
	delete[] e;
	delete[] f;
	return 0;
}