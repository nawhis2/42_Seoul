/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:39:53 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/03 13:25:12 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

static void chk() {
	system("leaks ex03");
}

int main()
{
	atexit(chk);
	// subject test.
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;


	// IMateriaSource* src = new MateriaSource();
	// Character* me = new Character("me");
	// Character* bob = new Character("bob");
	// AMateria* tmp;
	// AMateria* clone;
	// src->learnMateria(new Cure());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Cure());
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	
	// me->use(0, *bob); 
	// me->use(1, *bob); 
	// me->unequip(0); 
	// me->unequip(1);
	// me->unequip(2); 
	// me->unequip(3); 

	// // me->item_status(); 

	// src->learnMateria(new Ice());
	// src->learnMateria(new Ice());
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// clone = tmp->clone();
	// me->equip(clone);
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// clone = tmp->clone();
	// me->equip(clone);
	
	
	// me->use(0, *bob); 
	// me->use(1, *bob); 
	// me->use(2, *bob); 
	// me->use(3, *bob); 
	// me->use(4, *bob); 
	// me->item_status();

	// me->unequip(3); 
	// me->unequip(2); 
	// me->unequip(1); 
	// me->unequip(0); 

	// src->learnMateria(new Cure());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Cure());
	// src->learnMateria(new Cure());
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);	
	// me->item_status();
	
	// me->unequip(1); 
	// me->unequip(2); 
	// me->unequip(3); 
	// me->unequip(0); 
	// me->item_status();

	// std::cout << "\n\n" << std::endl;
	// src->learnMateria(new Ice());
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// src->learnMateria(new Cure());
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// src->learnMateria(new Ice());
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// src->learnMateria(new Cure());
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// 	std::cout << "***** bob copy character *****" << std::endl;
	// *bob = *me;
	// std::cout << "\n*me*" << std::endl;
	// me->item_status();

	// std::cout << "\n*bob*" << std::endl;
	// bob->item_status();

	
	// delete bob;
	// delete me;
	// delete src;
	return 0;
}