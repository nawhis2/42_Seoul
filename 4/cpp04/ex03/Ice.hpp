/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:42:01 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/30 10:40:22 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice();
	Ice(const Ice &copy);
	Ice &operator=(const Ice &copy);
	virtual ~Ice();

	virtual Ice* clone() const;
	virtual void use(ICharacter& target);
};

#endif