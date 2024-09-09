/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:57:55 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/09 16:46:35 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"
#include <signal.h>


#include <stdio.h>
#include <string.h>

/**
 * @brief: Sends string passed as param to the server to print
 * @param: server_pid - PID number from the server
 * @param: string_to_send - String sent 
*/
// void client(pid_t input_pid, char *string_to_send)
// {
    
// }

int main(int argc, char *argv[])
{
    int     input_pid;
    char    *input_str;

    if (argc == 3)
    {
        // input_pid = ft_atoi(argv[1]);
        input_pid = atoi(argv[1]);

        if (input_pid == -1)
            exit(EXIT_FAILURE);
        
        //Yes I should malloc and error handle here
        input_str = argv[2];
        
        //send signal
        kill(input_pid, SIGUSR1);
        
        
        //decode signal from bits to number?
        // printf("PID entered by the user is: %s", server_pid);
        
    }
    else
    {
        printf("Missing either/ both of two arguments: [1: Server PID], [2: String to send]\n");
        exit(EXIT_FAILURE);
    }
}
