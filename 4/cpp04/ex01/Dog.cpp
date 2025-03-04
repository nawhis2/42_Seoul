/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:52:03 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/03 13:15:39 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.getType();
	this->brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog &copy)
{
	std::cout << "Dog copy assignment operator called " << std::endl;
	this->type = copy.getType();
	delete (this->brain);
 	this->brain = new Brain(*copy.brain);
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "🐶 MOONG MOONG " << std::endl;
}

void Dog::checkBrain()
{
	std::cout << "Check Brain : " << &this->brain << " | " << this->brain << std::endl;
}

