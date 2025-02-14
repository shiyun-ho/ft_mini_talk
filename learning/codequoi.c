#include <signal.h>
#include <stdio.h>
#include <strings.h>

void sigint_handler(int signal)
{
    if (signal == SIGINT)
        printf("\n Intercepted SIGINT!\n");
}

void set_signal_action(void)
{
    struct sigaction act;

    bzero(&act, sizeof(act));
    act.sa_handler = &sigint_handler;
    sigaction(SIGINT, &act, NULL);
}

int main(void)
{
    set_signal_action();

    while (1)
    {
        continue;
    }
    return (0);
}