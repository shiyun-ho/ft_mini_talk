/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 12:48:25 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/30 18:48:25 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <sys/types.h>
#include <signal.h>

pid_t	g_client_pid;

void	bit_to_char(int *binary_form, siginfo_t *info)
{
	char	character;
	int		i;

	i = 0;
	character = 0;
	while (i < 8)
	{
		character = character << 1;
		character = character | binary_form[i];
		i++;
	}
	ft_printf("%c", character);
	if (character == '\0')
	{
		ft_printf("\n");
		kill(info->si_pid, SIGUSR2);
	}
}

void	signal_handler(int signum, siginfo_t *info, void *u_context)
{
	static int	binary_form[8];
	static int	bit_index;

	u_context += 1;
	u_context -= 1;
	if (signum == SIGUSR1)
	{
		binary_form[bit_index] = 0;
		bit_index++;
	}
	else if (signum == SIGUSR2)
	{
		binary_form[bit_index] = 1;
		bit_index++;
	}
	if (bit_index == 8)
	{
		bit_to_char(binary_form, info);
		bit_index = 0;
	}
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	sa;

	server_pid = getpid();
	ft_printf("Server started. Printing process id(pid): %i\n", server_pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (1);
}
