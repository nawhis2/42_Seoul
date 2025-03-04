/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:59:09 by sihkang           #+#    #+#             */
/*   Updated: 2024/04/30 10:40:18 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	int			nums;
	AMateria	*slot[4];
	
public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource& operator=(const MateriaSource &copy);	
	virtual ~MateriaSource();
	
	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);
};

#endif