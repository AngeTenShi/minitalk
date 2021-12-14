/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:07:07 by anggonza          #+#    #+#             */
/*   Updated: 2021/12/14 19:50:50 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"

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
	if (g_vars.i == 8)
	{
			ft_printf("%c\n", btoi(g_vars.buffer));
			g_vars.i = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	g_vars.i = 0;
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1) ;
}
