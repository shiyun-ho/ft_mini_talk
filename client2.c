/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:57:55 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/09 12:52:07 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"
#include <signal.h>


#include <stdio.h>

pid_t   server_pid;
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
void client(pid_t input_pid, char *string_to_send)
{
    //Check if input_pid matches the server pid

    //Read the docs on KILL --> server_pid 
    //can't send char directly over signals, but u can send via two different signals allowed
    // transfer bits to char 
    //print char
}

int main(int agrc, char *argv[])
{
    int     input_pid;
    char    *input_str;

    if (agrc == 3)
    {
        input_pid = ft_atoi(argv[1]);
        
        if (input_pid == -1 || input_pid <= 2261779)
            exit(EXIT_FAILURE);
        
        //Yes I should malloc and error handle here
        input_str = argv[1];
        
        kill(input_pid, SIGUSR1);
        printf("PID entered by the user is: %s", server_pid);
        
    }
    else
    {
        printf("Missing either/ both of two arguments: [1: Server PID], [2: String to send]\n");
        exit(EXIT_FAILURE);
    }
}
