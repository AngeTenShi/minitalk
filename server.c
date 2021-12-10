/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:07:07 by anggonza          #+#    #+#             */
/*   Updated: 2021/12/10 14:10:37 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_vars	g_vars;

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_vars.buffer[g_vars.i] = 1;
		g_vars.i++;
	}
	if (signum == SIGUSR2)
	{
		g_vars.buffer[g_vars.i] = 0;
		g_vars.i++;
	}
}

int	main(void)
{
	printf("%d\n", getpid());
	g_vars.i = 0;
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
	{
		if (g_vars.i == 8)
		{
			printf("%c\n", btoi(g_vars.buffer));
			g_vars.i = 0;
		}
	}
}
