/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:40:31 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/09 14:53:39 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* OCCF -> Not used */
Serializer::Serializer()
{
	std::cout << "Serializer constructor" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
	std::cout << "Serializer copy constructor" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	(void)copy;
	std::cout << "Serializer assignment operator" << std::endl;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor" << std::endl;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
