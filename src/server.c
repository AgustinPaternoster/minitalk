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
#include "../inc/minitalk.h"

t_server server;

void init_server(void)
{
    server.bit = 0;
    server.chr = 0;
	server.transmiting = 0;
	server.pid_client = 0;
}

void	print_bits(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		server.chr |= (0x01 << server.bit);
	server.bit++;
	if (server.bit == 8)
	{
		if (server.chr == '\0')
		{
			ft_printf("\nmesage client %d recibed\n", server.pid_client);
			send_signal_c(server.pid_client, SIGUSR2);
			init_server();
		}
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
	if (server.pid_client == 0)
	{	
		server.pid_client = info->si_pid;
		server.transmiting = 1;
	}
	else if (server.pid_client != info->si_pid && server.transmiting)
		send_signal_c(info->si_pid,SIGUSR2);
	if (server.pid_client == info->si_pid && server.transmiting)
		print_bits(sig,info,context);
}

void server_loop(void)
{
	while (1)
	{
		if (server.pid_client != 0);
			send_signal_c(server.pid_client,0);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int pid;
	int check;

	(void)argv;
	pid = getpid();
	sa.sa_sigaction = &client_conections;

	
	if (argc != 1)
		manage_errors_s(ERROR_2);
	if ((sigemptyset(&sa.sa_mask) != 0))
		manage_errors_s(ERROR_1);
	sa.sa_flags = SA_SIGINFO;
	if((sigaction(SIGUSR1, &sa, NULL) != 0))
		manage_errors_s(ERROR_1);	
	if((sigaction(SIGUSR2, &sa, NULL) != 0))
		manage_errors_s(ERROR_1);
	ft_printf("pid: %d\n", pid);
	init_server();
	server_loop();
	return (0);
}

