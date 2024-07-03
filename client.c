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
			send_signal(pid,SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		bit++;	
		while (checker != 1)
		{	
			usleep(100);
			send_signal(pid,0);
		}
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
		check_arg(argv[1],argv[2]);
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_to_server(pid, argv[2][i]);
			i++;
		}
	}
	else
		manage_errors(2);
	return (0);
}
