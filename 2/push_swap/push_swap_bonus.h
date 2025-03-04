/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:36:35 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 20:43:58 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "push_swap.h"
# include "get_next_line_bonus.h"

void	ft_operate(t_stack *a, t_stack *b);
void	ft_isok(t_stack *a, t_stack *b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_command(t_stack *a, t_stack *b, char *cmd);
void	ft_one_two_case(t_stack *a);

void	ft_s_bonus(t_stack *st);
void	ft_p_bonus(t_stack *st1, t_stack *st2);
void	ft_r_bonus(t_stack *st);
void	ft_rr_bonus(t_stack *st);
void	ft_ss_bonus(t_stack *a, t_stack *b);
void	ft_r_r_bonus(t_stack *a, t_stack *b);
void	ft_rr_r_bonus(t_stack *a, t_stack *b);

#endif
