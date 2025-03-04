/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:14:40 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 14:19:57 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_init(void)
{
	t_stack	*st;

	st = (t_stack *)malloc2(sizeof(t_stack));
	st->size = 0;
	st->head = NULL;
	st->tail = NULL;
	return (st);
}

void	ft_push(t_stack *st, t_list *new)
{
	if (st->size == 0)
	{
		new->prev = NULL;
		new->next = NULL;
		st->tail = new;
	}
	else if (st->size == 1)
	{
		new->next = st->head;
		new->prev = NULL;
		st->head->prev = new;
		st->tail->prev = new;
	}
	else
	{
		new->next = st->head;
		new->prev = NULL;
		st->head->prev = new;
	}
	st->head = new;
	st->size++;
}

void	ft_pop(t_stack *st)
{
	t_list	*tmp;

	tmp = NULL;
	if (st->size == 0)
		ft_errors();
	else if (st->size == 1)
	{
		tmp = st->head;
		free(tmp->cnt);
		tmp->cnt = NULL;
		free(tmp);
		tmp = NULL;
		st->head = NULL;
	}
	else if (st->size > 1)
	{
		tmp = st->head;
		st->head = st->head->next;
		st->head->prev = NULL;
		free(tmp->cnt);
		tmp->cnt = NULL;
		free(tmp);
		tmp = NULL;
	}
	st->size--;
}
