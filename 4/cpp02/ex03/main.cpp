/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:09:57 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/17 17:31:24 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <string>

bool	bsp( Point const a, Point const b, Point const c, Point const point );


int main( void ) 
{
	std::cout << std::boolalpha;

	Point a(1, 1);
	Point b(1, 5);
	Point c(5, 1);
	Point point(2,2);
	std::cout << bsp(a, b, c, point) << std::endl;
	
	Point a1(-1, -1);
	Point b1(0, 5);
	Point c1(5, 0);
	Point point1(0,0);
	std::cout << bsp(a1, b1, c1, point1) << std::endl;

	Point a2(10, 0);
	Point b2(0, 0);
	Point c2(5, 0);
	Point point2(3,0);
	std::cout << bsp(a2, b2, c2, point2) << std::endl;

	Point a3(123, 42);
	Point b3(0, 5);
	Point c3(67, 10);
	Point point3(33,22);
	std::cout << bsp(a3, b3, c3, point3) << std::endl;

	Point a4(2, 3);
	Point b4(4, 7);
	Point c4(6, 2);
	Point point4(4,4);
	std::cout << bsp(a4, b4, c4, point4) << std::endl;

	Point a5(-3, -2);
	Point b5(6, 0);
	Point c5(-1, 4);
	Point point5(1,1);
	std::cout << bsp(a5, b5, c5, point5) << std::endl;

	return 0;
}