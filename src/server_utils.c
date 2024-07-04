#include "../inc/minitalk.h"

void send_signal_c(int pid, int signal)
{
    int sig;

	sig = kill(pid, signal);
	if (sig != 0)
        reset_server(ERROR_4);
}

void reset_server(char *error)
{
    ft_putstr_fd(error,2);
    init_server();
}

void manage_errors_s(char *error)
{
    ft_putstr_fd(error,2);
    exit(EXIT_FAILURE);
}
