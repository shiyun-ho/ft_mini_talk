/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:51:36 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/29 22:10:43 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>

// void    confirmation(int signum)
// {
//     static int  msg_confirmed;

//     if (!msg_confirmed)
//     {
//         if (signum == SIGUSR1)
//         {
//             ft_printf("Message has been received successfully.\n");
//             msg_confirmed = 1;
//         }
//     }
// }

void    send_char_to_bit(pid_t input_pid, char character)
{
    int bit;
    
    bit = 7;
    while (bit >= 0)
    {
        if ((character & (1 << bit))  == 0)
            kill(input_pid, SIGUSR1);
        else
            kill(input_pid, SIGUSR2);        
        // usleep(1000);
        bit--;
    }
}

void signal_handler(int signum)
{
    if (signum == SIGUSR2)
        ft_printf("\nMessage received successfully by the server.\n");
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
    struct  sigaction sa;

    if (argc == 3)
    {
        input_pid = ft_atoi(argv[1]);
        if (input_pid == -1 || input_pid > 2261779)
            exit(EXIT_FAILURE);
        
        sa.sa_handler = &signal_handler;
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        
        i = 0;
        while(argv[2][i] != '\0')
        {
            send_char_to_bit(input_pid, argv[2][i]);
            i++;
            pause();
        }
        send_char_to_bit(input_pid, '\0');
        pause();
        // confirmation(signum);
        // usleep(1000);
    }
    else
    {
        ft_printf("Make sure that input argument(s) are as such: \n");
        ft_printf("./client [1: Server PID], [2: String to send]\n");
        exit(EXIT_FAILURE);
    }
}
