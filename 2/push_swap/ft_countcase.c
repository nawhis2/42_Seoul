/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:23:47 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/16 11:57:01 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nums(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = b->head;
	while (tmp)
	{
		if (b->size / 2 >= index)
		{
			tmp->cnt->b_count = index;
			tmp->cnt->b_rev = 0;
		}
		else
		{
			tmp->cnt->b_count = b->size - index;
			tmp->cnt->b_rev = 1;
		}
		ft_num_srt_a(a, tmp);
		tmp->cnt->both = 0;
		tmp = tmp->next;
		index++;
	}
}

void	ft_num_srt_a(t_stack *a, t_list *b_node)
{
	t_list	*tmp;
	int		index;
	int		min;
	int		position;

	index = 0;
	tmp = a->head;
	min = 2147483647;
	position = -1;
	if (a->size == 0)
	{
		b_node->cnt->a_count = 0;
		return ;
	}
	while (tmp)
	{
		if (b_node->val < tmp->val && min > tmp->val - b_node->val)
		{
			min = tmp->val - b_node->val;
			position = index;
		}
		tmp = tmp->next;
		index++;
	}
	ft_set_acnt(a, b_node, position);
}

void	ft_set_acnt(t_stack *a, t_list *b_node, int position)
{
	if (position == -1)
	{
		b_node->cnt->a_rev = 0;
		b_node->cnt->a_count = 1;
	}
	else if (position <= (a->size) / 2)
	{
		b_node->cnt->a_rev = 0;
		b_node->cnt->a_count = position;
	}
	else
	{
		b_node->cnt->a_rev = 1;
		b_node->cnt->a_count = a->size - position;
	}
}
