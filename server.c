/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:47:02 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/08 20:32:31 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"

#include <stdio.h>

/**
 * https://beej.us/guide/bgc/html/split/signal-handling.html
*/
void signal_handler()
{
    
}

/**
 * @brief: Upon launch, print PID. 
*/
void server()
{
    pid_t   server_pid;

    //Print PID upon launch
    server_pid = getpid();
    printf("Server has started. Printing pid: %i", server_pid);
    
    //Raise signal
    kill(server_pid, SIGUSR1);
    // signal(SIGUSR1, signal_handler);
    while(1)
    {
        
    }
    // stop the signal
    // kill(server_pid, SIGSTOP);
}

int main()
{
    server();
    return (1);
}
