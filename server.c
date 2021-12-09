/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:07:07 by anggonza          #+#    #+#             */
/*   Updated: 2021/12/09 17:57:29 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	g_buffer[8];
int	g_i;

void	signal_handler(int signum)
{
	printf("Rentre");
	if (signum == SIGUSR1)
	{
		g_buffer[g_i] = 1;
		g_i++;
	}
	if (signum == SIGUSR2)
	{
		g_buffer[g_i] = 0;
		g_i++;
	}
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1);
}
