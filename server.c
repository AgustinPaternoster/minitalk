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

#include "minitalk.h"

void	print_bits(int sig)
{
	static int	c;
	static int	bit;

	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 7)
	{
		write(1,&c,1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction sa; 
	sa.sa_handler = &print_bits;
	
	ft_printf("My Server PID is: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
