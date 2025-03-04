/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:52:08 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/03 13:20:00 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	/* abstract class cannot make instance */
	// Animal *ani = new Animal();



	// Animal *zoo[10];
	// std::cout << "* * * construct ZOO ! * * * " << std::endl;
	// for (int i = 0 ; i < 10 ; i++)
	// {
	// 	std::cout << "* * * " << i << " * * * " << std::endl;
	// 	if (i < 5)
	// 		zoo[i] = new Dog();
	// 	else
	// 		zoo[i] = new Cat();
	// 	zoo[i]->makeSound();
	// }

	
	// for (int i = 0 ; i < 10; i++)
	// {
	// 	std::cout << "* * * " << i << " * * * " << std::endl;
	// 	delete zoo[i];
	// }

	/* deep copy test */
	// Dog *A = new Dog();
	// Dog *B = new Dog();
	// A->checkBrain();
	// B->checkBrain();
	// *A = *B;
	// A->checkBrain();
	// B->checkBrain();
	// delete A;
	// delete B;
	return 0;
}