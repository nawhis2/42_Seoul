/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:36:07 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/16 12:45:31 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*tmp;

	tmp = NULL;
	if (argc == 1)
		exit(0);
	a = ft_stack_init();
	b = ft_stack_init();
	ft_argsplit(argc, argv, a);
	if (a->size < 3)
		ft_one_two_case(a);
	else
		tmp = ft_get_pivot(a);
	ft_operate(a, b);
	free(tmp);
	exit(0);
}

void	ft_one_two_case(t_stack *a)
{
	if (a->size == 1)
	{
		a->head->val = 1;
	}
	else if (a->size == 2)
	{
		if (a->head->val > a->tail->val)
		{
			a->head->val = 2;
			a->tail->val = 1;
		}
		else
		{
			a->head->val = 1;
			a->tail->val = 2;
		}
	}	
}

void	ft_command(t_stack *a, t_stack *b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 4))
		ft_s_bonus(a);
	else if (!ft_strncmp(cmd, "sb\n", 4))
		ft_s_bonus(b);
	else if (!ft_strncmp(cmd, "ss\n", 4))
		ft_ss_bonus(a, b);
	else if (!ft_strncmp(cmd, "ra\n", 4))
		ft_r_bonus(a);
	else if (!ft_strncmp(cmd, "rb\n", 4))
		ft_r_bonus(b);
	else if (!ft_strncmp(cmd, "rr\n", 4))
		ft_r_r_bonus(a, b);
	else if (!ft_strncmp(cmd, "pa\n", 4))
		ft_p_bonus(a, b);
	else if (!ft_strncmp(cmd, "pb\n", 4))
		ft_p_bonus(b, a);
	else if (!ft_strncmp(cmd, "rra\n", 5))
		ft_rr_bonus(a);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		ft_rr_bonus(b);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
		ft_rr_r_bonus(a, b);
	else
		ft_errors();
}

void	ft_operate(t_stack *a, t_stack *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd > 0)
	{
		ft_command(a, b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	ft_isok(a, b);
}

void	ft_isok(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	int		val;

	val = 1;
	tmp = a->head;
	if (b->size != 0)
	{
		ft_printf("KO\n");
		exit(0);
	}
	while (tmp)
	{
		if (tmp->val != val++)
		{
			ft_printf("KO\n");
			exit(1);
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}
