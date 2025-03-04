/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:18:56 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/16 12:39:56 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*pivot;

	a = ft_stack_init();
	b = ft_stack_init();
	ft_argsplit(argc, argv, a);
	ft_startingtest(a);
	ft_small_nums(a);
	pivot = ft_get_pivot(a);
	ft_switch_cases(a, b);
	ft_partition(a, b, pivot);
	while (b->size)
		ft_greedysrt(a, b);
	ft_finalsort(a);
	exit(0);
}

void	ft_startingtest(t_stack *a)
{
	t_list	*tmp;

	tmp = a->head;
	while (tmp && tmp->next)
	{
		if (tmp->val >= tmp->next->val)
			return ;
		tmp = tmp->next;
	}
	exit(0);
}

void	ft_finalsort(t_stack *a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = a->head;
	while (tmp)
	{
		if (tmp->val == 1)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i > a->size / 2)
		while (a->head->val != 1)
			ft_rr(a, 'a');
	else
		while (a->head->val != 1)
			ft_r(a, 'a');
}
