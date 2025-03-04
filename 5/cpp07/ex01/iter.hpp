/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:22:46 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/15 20:27:50 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T* addr, int length, void (*fp)(const T&))
{
	for (int i = 0; i < length; i++)
	{
		fp(addr[i]);
	}
	return ;
}

template <typename T1, typename T2>
void	iter(T1* addr, int length, T2 fp)
{
	for (int i = 0; i < length; i++)
	{
		fp(addr[i]);
	}
	return ;
}

template<typename T> 
void   print( T const & elem ) 
{
	std::cout << "print element : " << elem << std::endl;
	return ;
}

#endif