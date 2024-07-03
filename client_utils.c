#include "./inc/minitalk.h"

void manage_errors(int error)
{
    if (error == 1)
        ft_putstr_fd(ERROR_1,2);
    if (error == 2)
        ft_putstr_fd(ERROR_2,2);
    if (error == 3)
        ft_putstr_fd(ERROR_3,2);
    if (error == 4)
        ft_putstr_fd(ERROR_4,2);
    if (error == 5)
        ft_putstr_fd(ERROR_5,2);
    exit(EXIT_FAILURE);

}

void send_signal(int pid, int signal)
{
	int sig;

	sig = kill(pid, signal);
	if (sig != 0)
		manage_errors(4);
}

void check_arg(char *arg_1 , char *arg_2)
{
    int i;

    if (arg_2[0] == '\0')
        manage_errors(5);
    if (ft_atoi(arg_1) <= 0)
        manage_errors(3);
    i = 0;
    while(arg_1[i])
    {
        if(!ft_isdigit(arg_1[i]))
            manage_errors(3);
        i++;
    }
}