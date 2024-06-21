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

void	send_to_server(int pdi , char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pdi, SIGUSR1);
		else
			kill(pdi, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	main(int arc, char **argv)
{
	int i;
	int pdi;

	if (arc == 3)
	{		
		i = 0;
		pdi = ft_atoi(argv[1]);
		while(argv[1][i] != '\0')
		{
			send_to_server(pdi, argv[2][i]);
			i++;
		}
	}
	else
		ft_printf("Error");
	return (0);
}
