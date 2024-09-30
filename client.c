/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:51:36 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/30 19:16:04 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>

void	send_char_to_bit(pid_t input_pid, char character)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((character & (1 << bit)) == 0)
			kill(input_pid, SIGUSR1);
		else
			kill(input_pid, SIGUSR2);
		bit--;
		usleep(450);
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("Acknowledgement received by client from server\n");
		exit(EXIT_SUCCESS);
	}
}

void	send_msg_to_server(pid_t input_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char_to_bit(input_pid, str[i]);
		i++;
		usleep(450);
	}
	send_char_to_bit(input_pid, '\0');
}

/**
 * @brief: Sends str passed as param to server to print
 * @param: server_pid - PID number from server
 * @param: string_to send
 */
int	main(int argc, char *argv[])
{
	int					input_pid;
	struct sigaction	sa;

	if (argc == 3)
	{
		input_pid = ft_atoi(argv[1]);
		if (input_pid == -1 || input_pid > 2261779)
			exit(EXIT_FAILURE);
		sa.sa_handler = &signal_handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_msg_to_server(input_pid, argv[2]);
		pause();
	}
	else
	{
		ft_printf("./client [1: Server PID], [2: String to send]\n");
		exit(EXIT_FAILURE);
	}
}
