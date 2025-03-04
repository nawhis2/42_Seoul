/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:51:48 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/02 12:25:43 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	type = "";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = copy.getType();
}

Animal& Animal::operator=(const Animal &copy)
{
	std::cout << "Animal copy assignment operator overloading" << std::endl;
	type = copy.getType();
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound( void ) const
{
	std::cout << "❓ NOTHING" << std::endl;
}

std::string Animal::getType( void ) const
{
	return (this->type);
}