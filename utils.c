/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:41:55 by anggonza          #+#    #+#             */
/*   Updated: 2021/12/09 17:43:01 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	btoa(int tab[8])
{
	char	res;
	int		i;

	i = 0;
	res = 0;
	while (tab[i])
	{
		if (tab[i] == 1)
			res += power(2, i);
		i++;
	}
	return (res);
}

int	power(int first, int pow)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (i < pow)
	{
		res *= first;
		i++;
	}
	return (res);
}

int	*atob(int string)
{
	int	*ret;
	int	bin;
	int	i;

	i = 0;
	ret = (int *)malloc(sizeof(int) * 8);
	bin = 7;
	while (i < 8)
	{
		while (power(2, bin) > string)
		{
			ret[i] = 0;
			bin--;
			if (i == 7)
				break ;
			i++;
		}
		ret[i] = 1 ;
		string = string - power(2, bin);
		bin--;
		i++;
	}
	return (ret);
}
