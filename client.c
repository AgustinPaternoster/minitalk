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


void	recive_signal(int signal)
{
	if (signal == SIGUSR1)
		checker = 1;
	else if (signal == SIGUSR2)
		return ;
}


void	send_to_server(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		checker = 0;
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;	
		while (checker != 1)
			usleep(100);
	}
}
//test
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
		if (pid < 0)
		{
			ft_putstr_fd("Error\n",2);
			exit(EXIT_FAILURE);
		}
		while (argv[2][i] != '\0')
		{
			send_to_server(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_putstr_fd("Error\n",2);
		return (1);
	}
	return (0);
}
