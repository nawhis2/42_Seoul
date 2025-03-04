/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:09:24 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/02 12:20:57 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Wrong default constructor called" << std::endl;
	type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "Wrong copy constructor called" << std::endl;
	type = copy.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "Wrong copy assignment operator overloading" << std::endl;
	type = copy.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "⁉️ WRONG ANIMAL" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}