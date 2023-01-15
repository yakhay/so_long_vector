/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:12:04 by yakhay            #+#    #+#             */
/*   Updated: 2023/01/07 19:22:32 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_s(const char *str, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	if (k == 0)
		return (j);
	else
		return (i);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			j;
	long long	nb;

	i = ft_s(str, 1);
	j = ft_s(str, 0);
	nb = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb + str[i] - 48;
		if (str[i + 1] >= '0' && str[i + 1] <= '9' )
			nb *= 10;
		if (nb >= 9223372036854775807 && j == 1)
			return (-1);
		else if (nb > 9223372036854775807 && j == -1)
			return (0);
		i++;
	}
	return (nb * j);
}
