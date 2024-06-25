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

void	recive_signal(int signal)
{
	if (signal == SIGUSR1)
		//ft_printf("bit recibido\n");
		return;
	if (signal == SIGUSR2)
		//ft_printf("mensaje recibido\n");
		return;
}

void	send_to_server(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		pause();
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
		while (argv[2][i] != '\0')
		{
			send_to_server(pid, argv[2][i]);
			i++;
		}
		send_to_server(pid, argv[2][i]);
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
