/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:42:00 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/29 15:38:13 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:

public:
	Cure();
	Cure(const Cure &copy);
	Cure &operator=(const Cure &copy);
	virtual ~Cure();

	virtual Cure* clone() const;
	virtual void use(ICharacter& target);

};

#endif