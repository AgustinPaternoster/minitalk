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
#include "minitalk.h"

void	send_to_server(char *msg, int pdi)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			if ((msg[i] >> j) & 1)
				kill(pdi, SIGUSR1);
			else
				kill(pdi, SIGUSR2);
			usleep(200);
			j++;
		}
		i++;
	}
}

int	main(int arc, char **argv)
{
	if (arc == 3)
		send_to_server(argv[1], ft_atoi(argv[2]));
	else
		ft_printf("Error");
	return (0);
}
