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

void server_data(int c_pid)
{
    server.bit = 0;
    server.chr = 0;
	server.pid_client = c_pid;
}

void	print_bits(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		server.chr |= (0x01 << server.bit);
	server.bit++;
	if (server.bit == 8)
	{
		if (c = 0\)
			reset server;
			send SIGUSR2 cliente;
		ft_printf("%c", server.chr);
		server.bit = 0;
		server.chr = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

void	client_conections(int sig, siginfo_t *info, void *context)
{
	
	(void)context;
	//crear condiciones para filtrar señales
	// y rechazar señales de otro pid;

	print_bits();
}

void server_loop(void)
{
	while (1)
		if server.cliente_pdi != 0;
			check conections (server.cliente_pdi)
		usleep(50);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int pid;

	(void)argv;
	pid = getpid();
	sa.sa_sigaction = &client_conections;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("pid: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	server_loop();
	return (0);
}

