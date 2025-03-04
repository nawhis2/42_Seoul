/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:51:55 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/03 13:15:32 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.getType();
	this->brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assignment operator called " << std::endl;
	this->type = copy.getType();
	delete (this->brain);
 	this->brain = new Brain(*copy.brain);
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐱 MEOW MEOW" << std::endl;
}

void Cat::checkBrain()
{
	std::cout << this->brain << std::endl;
}