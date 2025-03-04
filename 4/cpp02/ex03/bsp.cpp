/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:37 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/17 17:05:28 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool	isInPlain(Point const &p1, Point const &p2, Point const &stand, Point const &point)
{
	float x = p2.get_x().toFloat() - p1.get_x().toFloat();
	float y = p2.get_y().toFloat() - p1.get_y().toFloat();

	float b = p1.get_y().toFloat() * x - y * p1.get_x().toFloat();
	
	if (y * stand.get_x().toFloat() + b < x * stand.get_y().toFloat())
	{
		if (y * point.get_x().toFloat() + b < x * point.get_y().toFloat())
			return (true);
	}
	else if (y * stand.get_x().toFloat() + b > x * stand.get_y().toFloat())
	{
		if (y * point.get_x().toFloat() + b > x * point.get_y().toFloat())
			return (true);
	}
	return (false);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	if(isInPlain(a, b, c, point) && \
	isInPlain(b, c, a, point) && \
	isInPlain(c, a, b, point))
		return (true);
	return (false);
}