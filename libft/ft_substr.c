/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhay <yakhay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:35:59 by yakhay            #+#    #+#             */
/*   Updated: 2022/10/24 14:37:07 by yakhay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j)
		return (ft_calloc(1, 1));
	else if (len > j - start)
		str = malloc((j - start) + 1);
	else
		str = malloc(len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s[start + j] && len > j)
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
// #include<stdio.h>
// int main()
// {
// 	char * s = ft_substr("malloc protection !", 100, 1);
// 	printf("%s", s);
// }
