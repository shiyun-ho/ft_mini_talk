#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int count = 0;

void sigint_handler(int signum)
{
    signal(SIGINT, sigint_handler);

    (void)signum;

    count++;
    printf("\nCount: %d\n", count);

    if (count == 2)
    {
        printf("Exiting! \n");
        exit(0);
    }
}

int main(void)
{
    signal(SIGINT, sigint_handler);

    printf("Try hitting CTL + C . . . \n");

    for(;;);
}