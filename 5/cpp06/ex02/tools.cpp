/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:08:16 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/10 14:41:50 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "tools.hpp"

Base * generate(void)
{
	srand(static_cast<unsigned int>(time(0)));
	int val = rand();
	Base *ret;
	if (val % 3 == 0)
		ret = new A;
	else if (val % 3 == 1)
		ret = new B;
	else
		ret = new C;
	return (ret);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "class A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "class B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "class C" << std::endl;		
	}
	else
		std::cout << "Noting to convert" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "class A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
		try 
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "class B" << std::endl;
			(void)b;
		}
		catch (std::exception &e)
		{
			try 
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "class C" << std::endl;
				(void)c;
			}
			catch (std::exception &e)
			{
				std::cout << "Nothing to convert" << std::endl;
			}	
		}
	}	
}
