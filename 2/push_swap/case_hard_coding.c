/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_hard_coding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:36:10 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 20:50:33 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_nums(t_stack *a)
{
	if (a->size == 1)
		exit(0);
	else if (a->size == 2)
	{
		if (a->head->val == a->tail->val)
			ft_errors();
		if (a->head->val > a->tail->val)
			ft_s(a, 'a');
		exit(0);
	}
}

void	ft_switch_cases(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		ft_case_three(a, b, 0);
	else if (a->size == 4)
		ft_case_four(a, b, 0);
	else if (a->size == 5)
		ft_case_five(a, b);
	else
		return ;
	exit(0);
}

void	ft_case_three(t_stack *a, t_stack *b, int offset)
{
	if (a->head->val == 1 + offset)
	{
		ft_p(b, a, 'b');
		if (a->head->val > a->tail->val)
			ft_s(a, 'a');
		ft_p(a, b, 'a');
	}
	else if (a->head->val == 2 + offset)
	{
		if (a->head->next->val == 3 + offset)
			ft_rr(a, 'a');
		else
			ft_s(a, 'a');
	}
	else if (a->head->val == 3 + offset)
	{
		ft_r(a, 'a');
		if (a->head->val == 2 + offset)
		{
			ft_s(a, 'a');
		}
	}
}

void	ft_case_four(t_stack *a, t_stack *b, int offset)
{
	t_list	*one_node;
	int		i;

	i = 0;
	one_node = a->head;
	while (one_node)
	{
		if (one_node->val == 1 + offset)
			break ;
		one_node = one_node->next;
		i++;
	}
	if (i < 2)
		while (i--)
			ft_r(a, 'a');
	else
	{
		i = 4 - i;
		while (i--)
			ft_rr(a, 'a');
	}
	ft_p(b, a, 'b');
	ft_case_three(a, b, 1 + offset);
	ft_p(a, b, 'a');
}

void	ft_case_five(t_stack *a, t_stack *b)
{
	t_list	*one_node;
	int		i;

	i = 0;
	one_node = a->head;
	while (one_node)
	{
		if (one_node->val == 1)
			break ;
		one_node = one_node->next;
		i++;
	}
	if (i < 2)
		while (i--)
			ft_r(a, 'a');
	else
	{
		i = 5 - i;
		while (i--)
			ft_rr(a, 'a');
	}
	ft_p(b, a, 'b');
	ft_case_four(a, b, 1);
	ft_p(a, b, 'a');
}
