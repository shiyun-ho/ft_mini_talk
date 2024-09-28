/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:51:36 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/28 21:30:49 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>

void    send_char_to_bit(pid_t input_pid, char character)
{
    int bit;
    
    bit = 7;
    while (bit >= 0)
    {
        //TODO: Fix bitwise operation
        //
        if ((character & (1 << bit))  == 0)
            kill(input_pid, SIGUSR1);
        else
            kill(input_pid, SIGUSR2);        
        usleep(2000);
        bit--;
    }
}

/**
 * @brief: Sends str passed as param to server to print
 * @param: server_pid - PID number from server
 * @param: string_to send
 */
int main(int argc, char *argv[])
{
    int     input_pid;
    int     i;

    if (argc == 3)
    {
        input_pid = ft_atoi(argv[1]);
        
        if (input_pid == -1 || input_pid > 2261779)
            exit(EXIT_FAILURE);
        
        i = 0;
        while(argv[2][i] != '\0')
        {
            send_char_to_bit(input_pid, argv[2][i]);
            i++;
        }
        send_char_to_bit(input_pid, '\0');
        usleep(100);
        // send_char_to_bit(input_pid, '\n');
    }
    else
    {
        ft_printf("Make sure that input argument(s) are as such: \n");
        ft_printf("./client [1: Server PID], [2: String to send]\n");
        exit(EXIT_FAILURE);
    }
}