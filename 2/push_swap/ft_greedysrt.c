/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greedysrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:12:16 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/16 11:58:39 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_greedysrt(t_stack *a, t_stack *b)
{
	t_list	*node;

	ft_nums(a, b);
	node = ft_findmin(b);
	ft_rotate_b(a, b, node);
	if (node->cnt->a_rev == -1)
	{
		ft_p(a, b, 'a');
		return ;
	}
	ft_sort_in_a(a, b, node);
}

void	ft_sort_in_a(t_stack *a, t_stack *b, t_list *node)
{
	if (a->size == 0)
		ft_p(a, b, 'a');
	else if (a->size == 1)
	{
		ft_p(a, b, 'a');
		if ((a->head->val > a->tail->val))
			ft_s(a, 'a');
	}
	else
	{
		if (node->cnt->a_rev)
			while (!ft_isascending(a, node->val))
				ft_rr(a, 'a');
		else
			while (!ft_isascending(a, node->val))
				ft_r(a, 'a');
		ft_p(a, b, 'a');
	}
}

void	ft_rotate_b(t_stack *a, t_stack *b, t_list *node)
{
	if (node->cnt->b_rev)
		while (node->cnt->both--)
			ft_rr_r(a, b);
	else
		while (node->cnt->both--)
			ft_r_r(a, b);
	while (node->cnt->b_count--)
	{
		if (node->cnt->b_rev)
			ft_rr(b, 'b');
		else
			ft_r(b, 'b');
	}
}

t_list	*ft_findmin(t_stack *b)
{
	t_list	*tmp;
	int		min;
	t_list	*ret;

	ret = 0;
	tmp = b->head;
	min = 2147483647;
	while (tmp)
	{
		if (tmp->cnt->a_rev == tmp->cnt->b_rev)
		{
			tmp->cnt->both = tmp->cnt->a_count;
			if (tmp->cnt->a_count > tmp->cnt->b_count)
				tmp->cnt->both = tmp->cnt->b_count;
			tmp->cnt->a_count -= tmp->cnt->both;
			tmp->cnt->b_count -= tmp->cnt->both;
		}
		if ((tmp->cnt->a_count + tmp->cnt->b_count + tmp->cnt->both) < min)
		{
			min = tmp->cnt->a_count + tmp->cnt->b_count + tmp->cnt->both;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}
