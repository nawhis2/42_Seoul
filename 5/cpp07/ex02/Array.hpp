/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:55:14 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/16 16:58:34 by sihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
	T*				arr;
	unsigned int	length;

public:
	Array()
	{
		std::cout << " array default constructor called" << std::endl;
		this->arr = new T[1]();
		this->length = 1;
	}
	Array(unsigned int n)
	{
		std::cout << " array constructor called" << std::endl;
		this->arr = new T[n]();
		this->length = n;
	}

	Array(const Array &copy)
	{
		std::cout << " array copy constructor called" << std::endl;
		this->arr = new T[copy.size()];
		this->length = copy.size();
		for (unsigned int i = 0 ; i < copy.size(); i++)
			arr[i] = static_cast<T>(copy.getElem(i));
	}

	Array &operator=(const Array &copy)
	{
		std::cout << " array assignment operator overloading" << std::endl;
		delete[] arr;
		this->arr = new T[copy.size()]();
		this->length = copy.size();
		for (int i = 0 ; i < copy.size(); i++)
			arr[i] = static_cast<T>(copy.getElem(i));
	}

	~Array()
	{
		std::cout << " array destructor called" << std::endl;
		delete[] arr;		
	}

	class outofBoundsException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "[Exception] The index is out of bounds.\n";
		}
	};

	unsigned int size() const
	{
		return (this->length);
	}

	T& getElem(long long idx) const
	{
		if (idx < 0 || idx >= this->length)
		{
			throw outofBoundsException();
		}
		return (this->arr[idx]);
	}

	void setElem(long long idx, T val)
	{
		if (idx < 0 || idx >= this->length)
		{
			throw outofBoundsException();
		}
		this->arr[idx] = val;
	}

	T& operator[](long long idx) const
	{
		if (idx < 0 || idx >= this->length)
		{
			throw outofBoundsException();
		}
		return (this->arr[idx]);
	}
};

#endif
