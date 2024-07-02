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

static void error_p(int error)
{
	if (error == 1)
		ft_putstr_fd(ERROR_1,2);
	if (error == 2)
		ft_putstr_fd(ERROR_2,2);
	if (error == 3)
		ft_putstr_fd(ERROR_3,2);
	exit(EXIT_FAILURE);
}

static void	recive_signal(int signal)
{
	if (signal == SIGUSR1)
		checker = 1;
	else if (signal == SIGUSR2)
		return ;
}


static void	send_to_server(int pid, char c)
{
	int	bit;
//() && (kill(pid, SIGUSR1) == -1)
//((c & (0x1 << bit)) && (kill (server_pid, SIGUSR1) == -1))
	bit = 0;
	while (bit < 8)
	{
		checker = 0;
		// if (c & (0x01 << bit))
		// 	if((kill(pid, SIGUSR1)) != 0)
		// 		ft_printf("err");
		// else
		// 	if((kill(pid, SIGUSR1)) != 0)
		// 		ft_printf("err");
		if ((c & (0x1 << bit)) && (kill (pid, SIGUSR1) == -1))
			print_error("ERROR IN SENDING SIGNAL");
		if (!(c & (0x1 << bit)) && (kill (pid, SIGUSR2) == -1))
			print_error("ERROR IN SENDING SIGNAL");

		bit++;	
		while (checker != 1)
			usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGUSR1, recive_signal);
	signal(SIGUSR2, recive_signal);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			error_p(3);
		while (argv[2][i] != '\0')
		{
			send_to_server(pid, argv[2][i]);
			i++;
		}
	}
	else
		error_p(2);
	return (0);
}
