/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:30:39 by anggonza          #+#    #+#             */
/*   Updated: 2021/12/07 16:16:35 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	client(int pid, char *buffer)
{
	if (pid == 0)
	{
		kill(pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	client(atoi(argv[0]), argv[1]);
}
