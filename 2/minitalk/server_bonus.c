/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:15:41 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/18 16:54:58 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_vars	g_vars;

static void	sigusr1_handler(int signum, siginfo_t *info, void *context)
{
	char	c;

	if (!context)
		return ;
	g_vars.bits = g_vars.bits >> 1;
	g_vars.bits += 128;
	g_vars.cnt = g_vars.cnt + 1;
	if (g_vars.cnt == 8)
	{
		c = g_vars.bits;
		write(1, &c, 1);
		g_vars.bits = 0;
		g_vars.cnt = 0;
	}
	kill(info->si_pid, signum);
}

static void	sigusr2_handler(int signum, siginfo_t *info, void *context)
{
	char	c;

	if (!context)
		return ;
	g_vars.bits = g_vars.bits >> 1;
	g_vars.cnt = g_vars.cnt + 1;
	if (g_vars.cnt == 8)
	{
		c = g_vars.bits;
		write(1, &c, 1);
		g_vars.cnt = 0;
		g_vars.bits = 0;
	}
	kill(info->si_pid, signum);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig1;
	struct sigaction	sig2;

	pid = getpid();
	ft_printf("server PID: %d\n", pid);
	sig1.sa_flags = SA_SIGINFO;
	sig1.__sigaction_u.__sa_sigaction = sigusr1_handler;
	sigaction(SIGUSR1, &sig1, NULL);
	sig2.sa_flags = SA_SIGINFO;
	sig2.__sigaction_u.__sa_sigaction = sigusr2_handler;
	sigaction(SIGUSR2, &sig2, NULL);
	while (1)
	{
		if (!usleep(100000))
		{
			g_vars.bits = 0;
			g_vars.cnt = 0;
		}
	}
	return (0);
}
