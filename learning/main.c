#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void handle_sigtstp(int sig)
{
    printf("Stop not allowed.\n");
}

int main(int argc, char *argv[])
{
    struct sigaction signal_action;
    signal_action.handler = &handle_sigtstp;
    sigaction(SIGTSTP, &signal_action, NULL);

    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result: %d * 5 = %d\n", x, x * 5);
    
    return (0);
}