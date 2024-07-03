/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:15:55 by apaterno          #+#    #+#             */
/*   Updated: 2024/06/14 13:16:05 by apaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <signal.h>

# define ERROR_1 "Signal error\n"
# define ERROR_2 "Arguments errors\n"
# define ERROR_3 "PID error\n"
# define ERROR_4 "Conection error\n"
# define ERROR_5 "Empty string\n"

typedef struct s_server
{
    int pid_client;
    unsigned char chr;
    int bit; 
    int transmiting;  
} t_server;

void manage_errors(int error);
void send_signal(int pid, int signal);
void check_arg(char *arg_1 , char *arg_2);
//server
void check_conextion_c(int pid, int signal, t_server *server);


#endif
