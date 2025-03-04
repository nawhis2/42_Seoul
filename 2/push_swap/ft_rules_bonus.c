/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:31:16 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 20:46:16 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_s_bonus(t_stack *st)
{
	int	tmp;

	if (st->size < 2)
		return ;
	tmp = st->head->val;
	st->head->val = st->head->next->val;
	st->head->next->val = tmp;
}

void	ft_p_bonus(t_stack *st1, t_stack *st2)
{
	t_list	*node;

	if (st2->size == 0)
		return ;
	node = (t_list *)malloc2(sizeof(t_list));
	node->cnt = (t_count *)malloc2(sizeof(t_count));
	node->val = st2->head->val;
	node->cnt->a_count = st2->head->cnt->a_count;
	node->cnt->b_count = st2->head->cnt->b_count;
	node->cnt->a_rev = st2->head->cnt->a_rev;
	node->cnt->b_rev = st2->head->cnt->b_rev;
	ft_push(st1, node);
	ft_pop(st2);
}

void	ft_r_bonus(t_stack *st)
{
	t_list	*tmp;

	if (st->size >= 2)
	{
		tmp = st->head;
		st->tail->next = tmp;
		tmp->prev = st->tail;
		st->head = st->head->next;
		st->head->prev = NULL;
		st->tail = tmp;
		st->tail->next = NULL;
	}
}

void	ft_rr_bonus(t_stack *st)
{
	t_list	*tmp;

	if (st->size >= 2)
	{
		tmp = st->tail;
		st->tail = st->tail->prev;
		st->tail->next = NULL;
		st->head->prev = tmp;
		tmp->next = st->head;
		tmp->prev = NULL;
		st->head = tmp;
	}
}
