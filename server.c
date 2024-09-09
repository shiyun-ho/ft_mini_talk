#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <stdio.h>

pid_t server_pid;

void    signal_handler(int signum)
{
    //verify if the server_pid is the same as input from client
    if (signum == SIGUSR1)
    {
        //Make the client only send SIGUSR1
        printf("Received signal SIGUSR1\n");
    }
    else if (signum == SIGUSR2)
    {
        //Print something else 
        printf("Received signal SIGUSR2\n");
    }
}

int main()
{
    pid_t   server_pid;
    struct  sigaction sa;

    server_pid = getpid();
    printf("Server has started. Enter process id (pid) for client: %i \n", server_pid);

    sa.sa_handler = signal_handler;

    //initialise sigaction
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    while(1)
    {
        pause();
    }
}