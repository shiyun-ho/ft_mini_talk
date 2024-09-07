/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:47:02 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/07 21:34:39 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "libft/libft.h"


#include <stdio.h>

void server()
{
    pid_t   server_pid;

    server_pid = getpid();
    printf("%i", server_pid);
    
    // stop the signal
    // kill(server_pid, SIGSTOP);
}

int main()
{
    server();
    return (1);
}
