/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:33 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/16 16:52:19 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
struct Point1 {
    float x, y;
};

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point( void );
	Point(const float a, const float b);
	Point(Point &p);
	Point& operator=(const Point &copy);
	~Point();

	Fixed get_x( void ) const;
	Fixed get_y( void ) const;
};

#endif
