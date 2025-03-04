/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:30 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/16 16:32:43 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void )
	: x (0), y (0) {}

Point::Point(const float a, const float b)
	: x (a), y (b) {}

Point::Point(Point &p)
	: x (p.x), y (p.y) {}

Point::~Point( void ) {}

Point& Point::operator=(const Point &copy)
{
	(void)copy;
	return (*this);
}

Fixed Point::get_x( void ) const
{
	return (this->x);
}

Fixed Point::get_y( void ) const
{
	return (this->y);
}
