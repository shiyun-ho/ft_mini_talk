/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:57:55 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/08 18:49:24 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>
/**
 * Note: Guard process id that I can send with the client
 * 
 *      pid of -1: sends a signal to kill ALL processes aside from this process
 * pid grouping - read up
 * run htop
 * handle cases where pid is of user root - reserve pid ranges for certain users
 * GUARD THE PID CAREFULLY WHAT IS ACCEPTED
 * 
 */
/**
 * @brief: Sends string passed as param to the server to print
 * @param: server_pid - PID number from the server
 * @param: string_to_send - String sent 
*/
void client(pid_t server_pid, char *string_to_send)
{
    
}

int main(int agrc, char **argv)
{
    if (agrc == 3)
    {
        //Error handling for invalid pid values to avoid rebooting
        if (argv[0][1] == '-1')
            return (NULL);
        
        printf("%s", argv[1]);
    }
    else
        printf("Missing two arguments: 1 --> Server PID, 2 --> String to send.\n");
}
