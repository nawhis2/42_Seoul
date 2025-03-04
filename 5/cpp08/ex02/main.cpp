/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:44:25 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/31 16:19:17 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{	
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		const MutantStack<int> mstack1 = mstack;
		std::cout << mstack1.top() << std::endl;
		std::cout << mstack1.size() << std::endl;
		//[...]
		MutantStack<int>::const_iterator it1 = mstack1.cbegin();
		MutantStack<int>::const_iterator ite1 = mstack1.cend();
		++it1;
		--it1;
		while (it1 != ite1)
		{
			std::cout << *it1 << std::endl;
			++it1;
		}
	}
	
	{	
	}

	std::cout << "std::list 와 출력값 비교하기(동일해야함)" << std::endl;
	{
		std::list<int> test_list;
		test_list.push_back(5);
		test_list.push_back(17);
		std::cout << test_list.back() << std::endl;
		test_list.pop_back();
		std::cout << test_list.size() << std::endl;
		test_list.push_back(3);
		test_list.push_back(5);
		test_list.push_back(737);
		//[...]
		test_list.push_back(0);
		std::list<int>::iterator _it = test_list.begin();
		std::list<int>::iterator _ite = test_list.end();
		++_it;
		--_it;
		while (_it != _ite)
		{
			std::cout << *_it << std::endl;
			++_it;
		}
	}
	return 0;
}