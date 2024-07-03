/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:13:47 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/14 13:13:54 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./inc/minitalk.h"

t_server server;

void server_data(void)
{
    server.bit = 0;
    server.chr = 0;
}

void	print_bits(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		server.chr |= (0x01 << server.bit);
	server.bit++;
	if (server.bit == 8)
	{
	
		ft_printf("%c", server.chr);
		server.bit = 0;
		server.chr = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	sa.sa_sigaction = &print_bits;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("pid: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	server_data();
	while (argc == 1)
	{
		pause ();
	}
	return (0);
}

