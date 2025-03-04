/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:11:33 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 14:06:01 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_inject_node(t_stack *st, int val)
{
	t_list	*injected_node;

	injected_node = (t_list *)malloc2(sizeof(t_list));
	injected_node->val = val;
	injected_node->cnt = (t_count *)malloc2(sizeof(t_count));
	injected_node->next = st->head;
	injected_node->prev = st->tail;
	st->tail->next = injected_node;
	st->size++;
	return (injected_node);
}

void	ft_remove_injection(t_stack *st, t_list *injected_node)
{
	st->tail->next = NULL;
	st->head->prev = NULL;
	st->size--;
	free(injected_node->cnt);
	injected_node->cnt = NULL;
	free(injected_node);
	injected_node = NULL;
}

t_list	*ft_find_min_node(t_list *injected_node, int val)
{
	t_list	*tmp;
	t_list	*min;
	int		i;

	i = val;
	min = injected_node;
	tmp = injected_node->next;
	while (tmp != injected_node)
	{
		if (i > tmp->val)
		{
			i = tmp->val;
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

int	ft_isascending(t_stack *st, int val)
{
	t_list	*injected_node;
	t_list	*min;
	int		i;

	injected_node = ft_inject_node(st, val);
	min = ft_find_min_node(injected_node, val);
	i = 0;
	while (i++ < st->size - 1)
	{
		if (min->val >= min->next->val)
		{
			ft_remove_injection(st, injected_node);
			return (0);
		}
		min = min->next;
	}
	ft_remove_injection(st, injected_node);
	return (1);
}

void	ft_getargv(t_stack *st, char *argv)
{
	t_list	*node;

	node = (t_list *)malloc2(sizeof(t_list));
	node->val = ft_atoi(argv);
	if (st->size == 0)
	{
		st->head = node;
		st->tail = node;
	}
	else if (st->size == 1)
	{
		st->tail = node;
		st->head->next = node;
		node->prev = st->head;
	}
	else
	{
		node->prev = st->tail;
		st->tail->next = node;
		st->tail = node;
	}
	node->cnt = (t_count *)malloc2(sizeof(t_count));
	node->next = NULL;
	st->size++;
}
