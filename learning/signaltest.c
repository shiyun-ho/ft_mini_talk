#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define SIG1 44
#define SIG2 45

/**
 * In seperate terminal:
 * * kill -n 44 (pid_value)
 * * >>> signal_handler() will be called
 * * main() terminal will show
 * * >>> Received signal with number: 44
*/
void signal_handler(int signum)
{
    printf("Received signal with number: %d\n", signum);
}

int main()
{
    printf("PID: %d\n", getpid());

    /* Overload signal handler */
    signal(SIG1, signal_handler);
    signal(SIG2, signal_handler);

    /* Start an endless loop */
    printf("Waiting for signals...\n");
    while (1)
    {
        sleep(1);
    }

    return 0;
}