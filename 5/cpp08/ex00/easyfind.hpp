/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:15:07 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/31 15:48:55 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
typename T::const_iterator easyfind(const T &container, int i)
{
	std::cout << "EASYFIND CONST" << std::endl;
	typename T::const_iterator b_iter = container.begin();
	typename T::const_iterator e_iter = container.end();
	return (std::find(b_iter, e_iter, i));
}

template <typename T>
typename T::iterator easyfind(T &container, int i)
{
	std::cout << "EASYFIND" << std::endl;
	typename T::iterator b_iter = container.begin();
	typename T::iterator e_iter = container.end();
	return (std::find(b_iter, e_iter, i));
}

#endif