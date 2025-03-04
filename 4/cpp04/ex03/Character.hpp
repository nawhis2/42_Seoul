/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:55:42 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/02 16:04:30 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ItemBox.hpp"

class Character : public ICharacter
{
private:
	AMateria 	*slot[4];
	ItemBox		*itembox;
	std::string name;
	Character();
	
public:
	Character(const std::string &name);
	Character(const Character &copy);
	Character &operator=(const Character &copy);
	virtual ~Character();
	
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	void item_status(void);

};

#endif