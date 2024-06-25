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

void	print_bits(int sig, siginfo_t *info, void *context)
{
	static int				bit;
	static unsigned char	chr;

	(void)context;
	if (sig == SIGUSR1)
		chr |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (chr == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
			usleep(100);
		}
		else
			ft_printf("%c", chr);
		bit = 0;
		chr = 0;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	sa.sa_sigaction = &print_bits;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	ft_printf("pid: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (argc == 1)
	{
		pause ();
	}
	return (0);
}
