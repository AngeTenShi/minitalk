/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:06:32 by anggonza          #+#    #+#             */
/*   Updated: 2022/04/12 11:59:24 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_vars
{
	int		i;
	int		buffer[8];
}	t_vars;

int		power(int first, int pow);
int		btoi(int *tab);
int		*atob(char string);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		parse(char *s);

#endif
