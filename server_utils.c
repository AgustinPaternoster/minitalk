#include "./inc/minitalk.h"

// void send_signal_c(int pid, int signal)
// {
//     int sig;

// 	sig = kill(pid, signal);
// 	if (sig != 0)
// 	{
//         ft_putstr_fd(ERROR_4,2);
//         t_server->bit = 0;
//         t_server->chr = 0;
//     }
// }

void server_data(t_server *server)
{
    server->bit = 0;
    server->chr = 0;
}