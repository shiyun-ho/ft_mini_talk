/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:57:55 by hshi-yun          #+#    #+#             */
/*   Updated: 2024/09/04 21:28:10 by hshi-yun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
