/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:21:55 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/18 16:55:02 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_vars
{
	volatile sig_atomic_t	bits;
	volatile sig_atomic_t	cnt;
}			t_vars;

#endif