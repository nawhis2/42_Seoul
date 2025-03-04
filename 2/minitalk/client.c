/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:15:44 by sihkang           #+#    #+#             */
/*   Updated: 2023/12/18 16:45:52 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_bits;

static void	sigusr1_handler(int signum)
{
	if (signum == 30)
		g_bits++;
}

static void	sigusr2_handler(int signum)
{
	if (signum == 31)
		g_bits++;
}

int	ft_sendsig(int server_pid, char *argv)
{
	int	cnt;
	int	mask;
	int	sendbits;

	mask = 1;
	sendbits = 0;
	while (*argv)
	{
		cnt = 8;
		while (cnt--)
		{
			if (*argv & mask)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(1000);
			usleep(100);
			sendbits++;
			*argv = (int)*argv >> 1;
		}
		argv++;
	}
	return (sendbits);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig1;
	struct sigaction	sig2;
	int					server_pid;
	int					sendbits;

	if (argc != 3)
	{
		ft_printf("ARGUMENTS ERROR\n");
		return (0);
	}
	sendbits = 0;
	sig1.__sigaction_u.__sa_handler = sigusr1_handler;
	sigaction(SIGUSR1, &sig1, NULL);
	sig2.__sigaction_u.__sa_handler = sigusr2_handler;
	sigaction(SIGUSR2, &sig2, NULL);
	server_pid = ft_atoi(argv[1]);
	sendbits = ft_sendsig(server_pid, argv[2]);
	if (g_bits == sendbits)
		ft_printf("COMPLETE MESSAGING\n");
	else
		ft_printf("ERROR TO SEND BIT\n");
	return (0);
}
