/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:30:39 by anggonza          #+#    #+#             */
/*   Updated: 2021/12/09 17:52:39 by anggonza         ###   ########.fr       */
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
			else
				kill(pid, SIGUSR2);
			j++;
		}
		usleep(500);
		temp_send = 0;
		free(temp_send);
		i++;
	}
}

int	main(int argc, char **argv)
{
	kill(atoi(argv[1]), SIGUSR1);
	//client(3166, "test");
}
