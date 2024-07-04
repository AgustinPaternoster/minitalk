/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:13:18 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/14 13:13:36 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./inc/minitalk.h"

int checker;

void	recive_signal(int sig, siginfo_t *info, void *context)
{
	static int connected;
	
	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{	checker = 1;
		connected = 1;
	}
	else if (sig == SIGUSR2)
		if (connected)
		{
			ft_printf("Message delivered.Conection finished\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			manage_errors_c(ERROR_6);
			exit(EXIT_FAILURE);
		}
}

void	send_to_server(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		checker = 0;
		if (c & (0x01 << bit))
			send_signal_s(pid,SIGUSR1);
		else
			send_signal_s(pid, SIGUSR2);
		bit++;	
		while (checker != 1)
		{	
			usleep(100);
			send_signal_s(pid,0);
		}
	}
}

// void server_conection(int sig, siginfo_t *info, void *context))
// {
// 	struct sigaction	sa;

// 	sa.sa_sigaction = &recive_signal;
// 	sa.sa_flags = SA_SIGINFO;
// 	sigemptyset(&sa.sa_mask);
// 	sigaction(SIGUSR1, &sa, NULL);
// 	sigaction(SIGUSR2, &sa, NULL);



// }

 static void client_loop(int pid, char *str)
 {
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		send_to_server(pid, str[i]);
			i++;
	}
	send_to_server(pid, '\0');
 }


int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_sigaction = &recive_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 3)
	{
		check_arg(argv[1],argv[2]);
		client_loop(ft_atoi(argv[1]), argv[2]);
	}
	else
		manage_errors_c(ERROR_2);
	return (0);
}
