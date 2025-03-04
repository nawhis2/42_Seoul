/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:40:33 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/14 12:08:33 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data a;
	Data *b = new Data;
	
	uintptr_t tmp1 = Serializer::serialize(&a);
	uintptr_t tmp2 = Serializer::serialize(b);
	std::cout << "Original: " << &a << std::endl;
	std::cout << "Original: " << b << std::endl;
	std::cout << "Serialize: " << tmp1 << std::endl;
	std::cout << "Serialize: " << tmp2 << std::endl;
	std::cout << "Deserialize: " << Serializer::deserialize(tmp1) << std::endl;
	std::cout << "Deserialize: " << Serializer::deserialize(tmp2) << std::endl;

	delete b;
	return (0);
}