/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:41:55 by anggonza          #+#    #+#             */
/*   Updated: 2021/12/10 15:02:04 by anggonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	btoi(int *tab)
{
	int	res;
	int	i;
	int	j;

	i = 0;
	j = 7;
	res = 0;
	while (i < 8)
	{
		if (tab[i] == 1)
			res += power(2, j);
		i++;
		j--;
	}
	return (res);
}

int	power(int first, int pow)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		res *= first;
		i++;
	}
	return (res);
}

int	*atob(char string)
{
	int	*ret;
	int	bin;
	int	i;

	i = 0;
	ret = (int *)malloc(sizeof(int) * 8);
	bin = 7;
	while (i < 8 && string != 0)
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
	if (string == 0)
		ret[i] = 0;
	return (ret);
}
