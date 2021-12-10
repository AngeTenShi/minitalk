/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:06:32 by anggonza          #+#    #+#             */
/*   Updated: 2021/12/10 13:30:32 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_vars
{
	int		i;
	int		buffer[8];
}	t_vars;

int		power(int first, int pow);
int		btoi(int tab[8]);
int		*atob(char string);

#endif
