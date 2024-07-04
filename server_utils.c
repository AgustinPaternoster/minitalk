#include "./inc/minitalk.h"

void send_signal_c(int pid, int signal)
{
    int sig;

	sig = kill(pid, signal);
	if (sig != 0)
        manage_errors_s(ERROR_4);
}

void manage_errors_s(char *error)
{
    ft_putstr_fd(error,2);
    init_server();
}
