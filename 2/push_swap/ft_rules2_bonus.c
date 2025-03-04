/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:43:32 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/16 11:43:29 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_ss_bonus(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size < 2 || b->size < 2)
		return ;
	tmp = a->head->val;
	a->head->val = a->head->next->val;
	a->head->next->val = tmp;
	tmp = b->head->val;
	b->head->val = b->head->next->val;
	b->head->next->val = tmp;
}

void	ft_r_r_bonus(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (a->size >= 2 && b->size >= 2)
	{
		tmp = a->head;
		a->tail->next = tmp;
		tmp->prev = a->tail;
		a->head = a->head->next;
		a->head->prev = NULL;
		a->tail = tmp;
		a->tail->next = NULL;
		tmp = b->head;
		b->tail->next = tmp;
		tmp->prev = b->tail;
		b->head = b->head->next;
		b->head->prev = NULL;
		b->tail = tmp;
		b->tail->next = NULL;
	}
}

void	ft_rr_r_bonus(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (a->size >= 2 && b->size >= 2)
	{
		tmp = a->tail;
		a->tail = a->tail->prev;
		a->tail->next = NULL;
		a->head->prev = tmp;
		tmp->next = a->head;
		tmp->prev = NULL;
		a->head = tmp;
		tmp = b->tail;
		b->tail = b->tail->prev;
		b->tail->next = NULL;
		b->head->prev = tmp;
		tmp->next = b->head;
		tmp->prev = NULL;
		b->head = tmp;
	}
}
