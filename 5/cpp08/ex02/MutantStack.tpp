/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:39:42 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/31 16:19:14 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack Default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &copy)
{
	if (this != &copy)
		std::stack<T>::operator=(copy);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack Destructor called" << std::endl;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::MutantStack::begin()
{
	std::cout << "begin func" << std::endl;
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	std::cout << "end func" << std::endl;
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::MutantStack::cbegin() const
{
	std::cout << "cbegin func" << std::endl;
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
	std::cout << "cend func" << std::endl;
	return this->c.end();
}

#endif