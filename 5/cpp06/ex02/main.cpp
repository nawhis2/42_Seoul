/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:23:52 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/14 12:05:27 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "tools.hpp"

int main()
{
	std::cout << "* Generate random derived class *" << std::endl;
	Base *p = generate();
	
	std::cout << "* pointer argument function * " << std::endl;
	identify(p);

	std::cout << "* reference argument function * " << std::endl;
	identify(*p);
	delete p;
}