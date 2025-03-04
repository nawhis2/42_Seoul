/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:33:47 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/31 16:00:24 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Span::Span();

Span::Span(const Span &copy)
{
	std::cout << "Span copy constructor called" << std::endl;
	this->arr = NULL;
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	std::cout << "Span assignment operator called" << std::endl;
	delete[] this->arr;
	this->arr = new int[copy.getLen()]();
	this->length = copy.getLen();
	this->occupied = copy.getOccup();
	for (unsigned int i = 0; i < this->occupied; i++)
		this->arr[i] = copy.getElem(i);
	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
	delete[] this->arr;
}

Span::Span(unsigned int N)
{
	std::cout << "Span array N constructor called" << std::endl;
	this->arr = new int[N]();
	this->length = N;
	this->occupied = 0;
}

void Span::addNumber(int num)
{
	if (this->occupied >= this->length)
		throw exceedArrayException();
	this->arr[this->occupied++] = num;
}

long Span::shortestSpan()
{
	if (this->occupied < 2)
		throw cannotFindSpanException();
	std::sort(arr, arr + occupied);
	long s_span = INT_MAX;
	for (unsigned int i = 1; i < occupied; i++)
	{
		long diff = abs(arr[i] - arr[i - 1]);
		if (diff < s_span)
			s_span = diff;
	}
	return s_span;
}

long Span::longestSpan()
{
	if (this->occupied < 2)
		throw cannotFindSpanException();
	return (*std::max_element(arr, arr + occupied) - *std::min_element(arr, arr + occupied));
}

unsigned int Span::getLen() const
{
	return (this->length);
}

unsigned int Span::getOccup() const
{
	return (this->occupied);
}

int Span::getElem(unsigned int idx) const
{
	if (idx >= this->length)
		throw outOfBoundException();
	return (this->arr[idx]);
}

const char * Span::exceedArrayException::what() const throw()
{
	return "[Exception] Caanot add number over the array size.";
}

const char * Span::cannotFindSpanException::what() const throw()
{
	return "[Exception] Cannot find span value in this array.";
}

const char * Span::outOfBoundException::what() const throw()
{
	return "[Exception] The index is Out of bound in array.";
}