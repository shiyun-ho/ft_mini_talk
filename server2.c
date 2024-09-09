/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:47:02 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/09 15:34:36 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"

#include <stdio.h>

pid_t   server_pid;

void    signal_handler(int signum)
{
    static char message[100] = {0};
    static int message_index = 0;
    static int message_type = 0;
    static pid_t received_pid = 0;
    
    if (signum == SIGUSR1)
    {
        printf("Received signal!\n");
        char c = (char)sigval    
        
    }
}

int     main()
{
    // pid_t   server_pid;
    
    server_pid = getpid();
    printf("Server has started. Printing process id(pid): %i\n", server_pid);

    while (1)
    {
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);
        //wait for signal
        pause();
    }
    return (1);
}
