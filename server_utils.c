#include "./inc/minitalk.h"

void check_conextion_c(int pid, int signal, t_server *server)
{
    int sig;

	sig = kill(pid, signal);
	if (sig != 0)
	{
        //ft_putstr_fd(ERROR_4,2);
        server->bit = 0;
        server->chr = 0;
        ft_printf("\nERROR\n");
    }
}
