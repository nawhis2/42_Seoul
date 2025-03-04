/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItemBox.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:34:42 by sihkang           #+#    #+#             */
/*   Updated: 2024/05/02 13:53:37 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEMBOX_HPP
# define ITEMBOX_HPP

#include "AMateria.hpp"

typedef struct s_node
{
	AMateria	  *materia;
	struct s_node *next;
}	t_node;

class ItemBox
{
private:
	t_node *head;
	int	   nums;
	
public:
	ItemBox();
	ItemBox(const ItemBox &copy);
	ItemBox &operator=(const ItemBox &copy);
	virtual ~ItemBox();

	int		getNums() const;
	t_node	*getHead() const;
	void	addMateria(AMateria *materia);
};

#endif