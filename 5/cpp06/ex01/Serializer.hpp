/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:40:30 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/09 14:51:25 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

typedef unsigned long uintptr_t;

typedef struct s_data
{
	int mem_int1;
}	Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &copy);
	Serializer &operator=(const Serializer &copy);
	~Serializer();
	
public:
	static uintptr_t	serialize(Data *ptr);
	static Data		*deserialize(uintptr_t raw);
};

#endif