/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:24:24 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/10 12:25:24 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <random>

Base * generate(void);
void identify(Base *p);
void identify(Base &p);

#endif