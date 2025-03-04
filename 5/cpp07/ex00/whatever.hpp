/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:08:13 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/13 14:17:54 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T& min(T& a, T& b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

template <>
char* &min(char* &a, char* &b)
{
	int res = strcmp(a, b);
	if (res >= 0)
		return (b);
	else
		return (a);
}

template <typename T>
T& max(T& a, T& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

template <>
char* &max(char* &a, char* &b)
{
	int res = strcmp(a, b);
	if (res > 0)
		return (a);
	else
		return (b);
}


#endif