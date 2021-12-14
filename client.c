/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:30:39 by anggonza          #+#    #+#             */
/*   Updated: 2021/12/14 19:27:53 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>

void	client(int pid, char *buffer)
{
	int	i;
	int	j;
	int	*temp_send;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		temp_send = atob(buffer[i]);
		while (j < 8)
		{
			if (temp_send[j] == 1)
				kill(pid, SIGUSR1);
			if (temp_send[j] == 0)
				kill(pid, SIGUSR2);
			usleep(500);
			j++;
		}
		j = 0;
		free(temp_send);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	client(pid, argv[2]);
}
