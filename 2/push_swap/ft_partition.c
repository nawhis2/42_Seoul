/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:25:25 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/16 11:42:22 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_partition(t_stack *a, t_stack *b, int *pivot)
{
	t_list	*node;
	int		size;

	size = a->size;
	while (size--)
	{
		node = a->head;
		if (node->val <= pivot[0])
		{
			ft_p(b, a, 'b');
			ft_r(b, 'b');
		}
		else if (node->val > pivot[0] && node->val <= pivot[1])
			ft_p(b, a, 'b');
		else
			ft_r(a, 'a');
	}
	size = a->size;
	while (size--)
		ft_p(b, a, 'b');
}

void	ft_argsplit(int argc, char **argv, t_stack *a)
{
	char	**arg_split;
	int		i;

	i = 1;
	arg_split = ft_split(argv[i], ' ');
	if (!arg_split[1])
	{
		while (i < argc)
			ft_getargv(a, argv[i++]);
	}
	else
	{
		i = 0;
		if (argv[2])
			ft_errors();
		while (arg_split[i])
			ft_getargv(a, arg_split[i++]);
	}
	i = 0;
	while (arg_split[i])
		free(arg_split[i++]);
	free(arg_split);
}
