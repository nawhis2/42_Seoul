/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:31:16 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 20:49:25 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_stack *st, char c)
{
	int	tmp;

	if (st->size < 2)
		return ;
	tmp = st->head->val;
	st->head->val = st->head->next->val;
	st->head->next->val = tmp;
	ft_printf("s%c\n", c);
}

void	ft_p(t_stack *st1, t_stack *st2, char c)
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
	ft_printf("p%c\n", c);
}

void	ft_r(t_stack *st, char c)
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
	ft_printf("r%c\n", c);
}

void	ft_rr(t_stack *st, char c)
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
	ft_printf("rr%c\n", c);
}

void	ft_errors(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
