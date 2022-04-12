/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggonza <anggonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:41:55 by anggonza          #+#    #+#             */
/*   Updated: 2022/04/12 11:33:00 by anggonza         ###   ########.fr       */
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
	if (pow != 0)
		return (first * power(first, pow - 1));
	else
		return (1);
}

int	*atob(char string)
{
	int	*ret;
	int	bin;
	int	i;

	i = 0;
	ret = ft_calloc(8, 4);
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

int     ft_atoi(const char *str)
{
        long int        i;
        long int        num;
        long int        neg;

        neg = 1;
        num = 0;
        i = 0;
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
                || str[i] == '\v' || str[i] == '\b' || str[i] == '\f')
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        neg = -1;
                i++;
        }
        while (str[i])
        {
                if (str[i] >= '0' && str[i] <= '9')
                        num = (str[i] - 48) + (num * 10);
                else
                        return ((int)num * neg);
                i++;
        }
        return ((int)num * neg);
}

