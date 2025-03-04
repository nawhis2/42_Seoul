/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:19:41 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/31 15:52:23 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>

class Span
{
private:
	int 		 *arr;
	unsigned int length;
	unsigned int occupied;
	Span();

public:
	Span(unsigned int N);
	Span(const Span &copy);
	Span &operator=(const Span &copy);
	~Span();

	unsigned int getLen() const;
	unsigned int getOccup() const;
	int getElem(unsigned int idx) const;

	
	long shortestSpan();
	long longestSpan();

	void addNumber(int num);
	template<typename T>
	void addNumber(const T &container)
	{
		typename T::const_iterator iter;
		for (iter = container.begin(); iter != container.end(); ++iter)
		{
			if (this->occupied > this->length)
				throw exceedArrayException();
			this->arr[this->occupied++] = *iter;
		}
	}

	class exceedArrayException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	class cannotFindSpanException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	class outOfBoundException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};
};

#endif